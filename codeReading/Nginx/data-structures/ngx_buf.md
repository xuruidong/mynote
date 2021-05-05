# 缓冲区结构 ngx_buf.c
[参考](https://initphp.blog.csdn.net/article/details/50611021)  

Nginx的buf缓冲区数据结构，主要用来存储非常大块的内存。ngx_buf_t数据结构也贯穿了整个Nginx。

Nginx的缓冲区设计是比较灵活的。

* 可以自定义管理业务层面的缓冲区链表；
* 也可以将空闲的缓冲区链表交还给内存池pool->chain结构。


__缓冲区ngx_buf_t是nginx处理大数据的关键数据结构，它既应用于内存数据也应用于磁盘数据。__

## 一、数据结构定义
### 1. 缓冲区内存块的数据结构 ngx_buf_t
```
typedef void *            ngx_buf_tag_t;

typedef struct ngx_buf_s  ngx_buf_t;

struct ngx_buf_s {
    u_char          *pos;           /* 待处理数据的开始标记  */
    u_char          *last;          /* 待处理数据的结尾标记 */
    off_t            file_pos;      /* 处理文件时，待处理的文件开始标记  */
    off_t            file_last;     /* 处理文件时，待处理的文件结尾标记  */

    u_char          *start;         /* start of buffer */  /* 缓冲区开始的地址 */
    u_char          *end;           /* end of buffer */     /* 缓冲区结尾的地址 */
    ngx_buf_tag_t    tag;           /* 缓冲区标记地址，是一个void类型的指针。 */
    ngx_file_t      *file;          /* 引用的文件 */
    ngx_buf_t       *shadow;


    /* the buf's content could be changed */
    unsigned         temporary:1;   /* 标志位，为1时，内存可修改 */

    /*
     * the buf's content is in a memory cache or in a read only memory
     * and must not be changed
     */
    unsigned         memory:1;      /* 标志位，为1时，内存只读 */

    /* the buf's content is mmap()ed and must not be changed */
    unsigned         mmap:1;        /* 标志位，为1时，mmap映射过来的内存，不可修改 */

    unsigned         recycled:1;    /* 标志位，为1时，可回收 */
    unsigned         in_file:1;     /* 标志位，为1时，表示处理的是文件 */
    unsigned         flush:1;       /* 标志位，为1时，表示需要进行flush操作 */
    unsigned         sync:1;        /* 标志位，为1时，表示可以进行同步操作，容易引起堵塞 */
    unsigned         last_buf:1;    /* 标志位，为1时，表示为缓冲区链表ngx_chain_t上的最后一块待处理缓冲区 */
    unsigned         last_in_chain:1;/* 标志位，为1时，表示为缓冲区链表ngx_chain_t上的最后一块缓冲区 */

    unsigned         last_shadow:1; /* 标志位，为1时，表示是否是最后一个影子缓冲区 */
    unsigned         temp_file:1;   /* 标志位，为1时，表示当前缓冲区是否属于临时文件 */

    /* STUB */ int   num;
};
```
* 从上面这个数据结构中，可以看到ngx_buf_t结构，即可以处理内存，也可以处理文件
* Nginx使用了位域的方法，节省存储空间
* 每个buf都记录了开始和结束点以及未处理的开始和结束点，因为缓冲区的内存申请了之后，是可以被复用的
* 所有缓冲区需要的数据结构以及缓冲区的buf内存块都会被分配到内存池上面

### 2. 缓冲区链表结构 ngx_chain_t
```
/**
 * 缓冲区链表结构，放在pool内存池上面
 */
struct ngx_chain_s {
    ngx_buf_t    *buf;
    ngx_chain_t  *next;
};
```
* 是否还记得内存池结构中，有一个数据结构pool->chain就是保存空闲的缓冲区链表的
* Nginx的缓冲区ngx_buf_t，通过ngx_chain_t链表结构进行关联和管理
* 通过链表的方式实现buf有一个非常大的好处：如果一次需要缓冲区的内存很大，那么并不需要分配一块完整的内存，只需要将缓冲区串起来就可以了

## 二、数据结构图
。。。。。。

## 