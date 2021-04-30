
# ngx_array

[from](https://initphp.blog.csdn.net/article/details/50601742)
Nginx的内存管理都是围绕内存池来实现的，包括array数组类型也是基于Nginx的pool来实现数据结构。

Nginx的Array结构设计得非常小巧，主要用于存储小块内存。Nginx的数组每个元素的大小是固定的。

## 数据结构
```
typedef struct {
    void        *elts;
    ngx_uint_t   nelts;
    size_t       size;
    ngx_uint_t   nalloc;
    ngx_pool_t  *pool;
} ngx_array_t;
```

* *elts : 指向数组的第一个元素的指针地址
* nelts : 未使用的元素的计数器
* size : 每个元素的大小，元素大小是固定的
* nalloc : 一共分配了多少个元素。如果元素不够用，Nginx会数组会进行自动扩容
* pool : 数组的数据结构ngx_array_t和元素所需要的内存都会分配在pool内存池上

## 数据结构图

。。。

## 具体实现

### 1. 创建数组 ngx_array_create

可以定义创建多少个数组元素，并且可以定义每个元素的size。  
```
ngx_array_t *
ngx_array_create(ngx_pool_t *p, ngx_uint_t n, size_t size)
{
    ngx_array_t *a;

    /* 在内存池 pool上面 分配一段内存给 ngx_array数据结构*
    a = ngx_palloc(p, sizeof(ngx_array_t));
    if (a == NULL) {
        return NULL;
    }

    /**
     * 数组初始化
     */
    if (ngx_array_init(a, p, n, size) != NGX_OK) {
        return NULL;
    }

    return a;
}
```

```
static ngx_inline ngx_int_t
ngx_array_init(ngx_array_t *array, ngx_pool_t *pool, ngx_uint_t n, size_t size)
{
    /*
     * set "array->nelts" before "array->elts", otherwise MSVC thinks
     * that "array->nelts" may be used without having been initialized
     */

    array->nelts = 0;
    array->size = size;
    array->nalloc = n;
    array->pool = pool;

    array->elts = ngx_palloc(pool, n * size);
    if (array->elts == NULL) {
        return NGX_ERROR;
    }

    return NGX_OK;
}
```

### 2. 数组销毁 ngx_array_destroy

数组销毁设计的也挺讲究的，会去检查数组是否在内存池内存块上的结尾部分，如果在结尾部分，则将内存回收给内存池
```
void
ngx_array_destroy(ngx_array_t *a)
{
    ngx_pool_t  *p;

    p = a->pool;

    /**
     * PS：你估计比较奇怪，为何数组的内存空间一定会分配在内存池（pool->d存储小内存）上面
     * 如果比较大的内存块不是会存储在内存池的pool->large上面吗？
     * 当我们全局搜索Nginx代码中ngx_array_create方法的时候发现，Nginx的数组都是比较小的，存储的数据量也
     * 并不是很大。所以ngx_array_t适合存储小块的内存。
     */
 
    /**
     * 如果数组元素的末尾地址和内存池pool的可用开始的地址相同
     * 则将内存池pool->d.last移动到数组元素的开始地址，相当于清除当前数组的内容
     */
    if ((u_char *) a->elts + a->size * a->nalloc == p->d.last) {
        p->d.last -= a->size * a->nalloc;
    }
 
    /**
     * 如果数组的数据结构ngx_array_t的末尾地址和内存池pool的可用开始地址相同
     * 则将内存池pool->d.last移动到数组元素的开始地址，相当于清除当前数组的内容
     */

    if ((u_char *) a->elts + a->size * a->nalloc == p->d.last) {
        p->d.last -= a->size * a->nalloc;
    }

    if ((u_char *) a + sizeof(ngx_array_t) == p->d.last) {
        p->d.last = (u_char *) a;
    }
}
```

### 3. 添加一个元素 ngx_array_push

```

```