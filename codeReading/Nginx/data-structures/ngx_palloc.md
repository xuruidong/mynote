# ngx_palloc


### 5. 使用内存池分配一块内存ngx_palloc和ngx_pnalloc
```
void *
ngx_palloc(ngx_pool_t *pool, size_t size)
{
    /* 判断每次分配的内存大小，如果超出pool->max的限制，则需要走大数据内存分配策略 */
#if !(NGX_DEBUG_PALLOC)
    if (size <= pool->max) {
        return ngx_palloc_small(pool, size, 1);
    }
#endif

    /* 走大数据分配策略 ，在pool->large链表上分配 */
    return ngx_palloc_large(pool, size);
}
```
ngx_pnalloc 和 ngx_palloc 流程一样，但不考虑内存对齐。  
```
static ngx_inline void *
ngx_palloc_small(ngx_pool_t *pool, size_t size, ngx_uint_t align)
{
    u_char      *m;
    ngx_pool_t  *p;

    p = pool->current;

    /*
    * 循环读取缓存池链p->d.next的各个的ngx_pool_t节点，
    * 如果剩余的空间可以容纳size，则返回指针地址
    *
    * 这边的循环，实际上最多只有4次，具体可以看ngx_palloc_block函数
    * */
    do {
        m = p->d.last;

        if (align) {
            /* 对齐操作,会损失内存，但是提高内存使用速度 */
            m = ngx_align_ptr(m, NGX_ALIGNMENT);
        }

        if ((size_t) (p->d.end - m) >= size) {
            p->d.last = m + size;

            return m;
        }

        p = p->d.next;

    } while (p);

    /* 如果没有缓存池空间没有可以容纳大小为size的内存块，则需要重新申请一个缓存池pool节点 */
    return ngx_palloc_block(pool, size);
}

```


### 6. ngx_palloc_block，内存池扩容

申请一个新的缓存池 ngx_pool_t  
新的缓存池会挂载在主缓存池的 数据区域 （pool->d->next）  

```
static void *
ngx_palloc_block(ngx_pool_t *pool, size_t size)
{
    u_char      *m;
    size_t       psize;
    ngx_pool_t  *p, *new;

    psize = (size_t) (pool->d.end - (u_char *) pool);

    /* 申请新的块 */
    m = ngx_memalign(NGX_POOL_ALIGNMENT, psize, pool->log);
    if (m == NULL) {
        return NULL;
    }

    new = (ngx_pool_t *) m;

    new->d.end = m + psize;
    new->d.next = NULL;
    new->d.failed = 0;

    /* 分配size大小的内存块，返回m指针地址 */
    m += sizeof(ngx_pool_data_t);
    m = ngx_align_ptr(m, NGX_ALIGNMENT);
    new->d.last = m + size;

    /**
	 * 缓存池的pool数据结构会挂载子节点的ngx_pool_t数据结构
	 * 子节点的ngx_pool_t数据结构中只用到pool->d的结构，只保存数据
	 * 每添加一个子节点，p->d.failed就会+1，当添加超过4个子节点的时候，
	 * pool->current会指向到最新的子节点地址
	 *
	 * 这个逻辑主要是为了防止pool上的子节点过多，导致每次ngx_palloc循环pool->d.next链表
	 * 将pool->current设置成最新的子节点之后，每次最大循环4次，不会去遍历整个缓存池链表
	 */
    for (p = pool->current; p->d.next; p = p->d.next) {
        if (p->d.failed++ > 4) {
            pool->current = p->d.next;
        }
    }

    p->d.next = new;

    return m;
}
```

分配一块大内存，挂载到pool->large链表上ngx_palloc_large：  
```
static void *
ngx_palloc_large(ngx_pool_t *pool, size_t size)
{
    void              *p;
    ngx_uint_t         n;
    ngx_pool_large_t  *large;

    p = ngx_alloc(size, pool->log);
    if (p == NULL) {
        return NULL;
    }

    n = 0;

    /* 去pool->large链表上查询是否有NULL的，只在链表上往下查询3次，主要判断大数据块是否有被释放的，如果没有则只能跳出*/
    for (large = pool->large; large; large = large->next) {
        if (large->alloc == NULL) {
            large->alloc = p;
            return p;
        }

        if (n++ > 3) {
            break;
        }
    }
    /*  为什么是 ngx_palloc_small ？ 
     *  ngx_pool_large_t数据结构保存在小内存区，然后添加到 pool->large 头部
     */
    large = ngx_palloc_small(pool, sizeof(ngx_pool_large_t), 1);
    if (large == NULL) {
        ngx_free(p);
        return NULL;
    }

    large->alloc = p;
    large->next = pool->large;
    pool->large = large;

    return p;
}
```

### 7. 大内存块的释放ngx_pfree
在pool->large链上循环搜索，并且只释放内容区域，不释放ngx_pool_large_t数据结构  
```
ngx_int_t
ngx_pfree(ngx_pool_t *pool, void *p)
{
    ngx_pool_large_t  *l;

    for (l = pool->large; l; l = l->next) {
        if (p == l->alloc) {
            ngx_log_debug1(NGX_LOG_DEBUG_ALLOC, pool->log, 0,
                           "free: %p", l->alloc);
            ngx_free(l->alloc);
            l->alloc = NULL;

            return NGX_OK;
        }
    }

    return NGX_DECLINED;
}
```

### 8. cleanup机制 可以回调函数清理数据

```
typedef void (*ngx_pool_cleanup_pt)(void *data);

typedef struct ngx_pool_cleanup_s  ngx_pool_cleanup_t;

struct ngx_pool_cleanup_s {
    ngx_pool_cleanup_pt   handler;
    void                 *data;
    ngx_pool_cleanup_t   *next;
};
```
Nginx的内存池cleanup机制，设计的非常巧妙。pool->cleanup本身是一个链表，每个ngx_pool_cleanup_t的数据结构上，保存着内存数据的本身cleanup->data和回调清理函数cleanup->handler。  
通过cleanup的机制，我们就可以在内存池上保存例如文件句柄fd的资源。当我们调用ngx_destroy_pool方法销毁内存池的时候，首先会来清理pool->cleanup，并且都会执行c->handler(c->data)回调函数，用于清理资源。  
Nginx的这个机制，最显著的就是让文件描述符和需要自定义清理的数据的管理变得更加简单。

#### 分配一个cleanup结构
```
ngx_pool_cleanup_t *
ngx_pool_cleanup_add(ngx_pool_t *p, size_t size)
{
    ngx_pool_cleanup_t  *c;

    c = ngx_palloc(p, sizeof(ngx_pool_cleanup_t));
    if (c == NULL) {
        return NULL;
    }

    if (size) {
        c->data = ngx_palloc(p, size);
        if (c->data == NULL) {
            return NULL;
        }

    } else {
        c->data = NULL;
    }

    c->handler = NULL;
    c->next = p->cleanup;

    p->cleanup = c;

    ngx_log_debug1(NGX_LOG_DEBUG_ALLOC, p->log, 0, "add cleanup: %p", c);

    return c;
}

```