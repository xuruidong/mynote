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
大内存分配：
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

    for (large = pool->large; large; large = large->next) {
        if (large->alloc == NULL) {
            large->alloc = p;
            return p;
        }

        if (n++ > 3) {
            break;
        }
    }

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
