
[openresty 数据共享方式](https://www.cnblogs.com/liekkas01/p/12748757.html)  

在ctx 保存数据(ctx._private_data = "xxx")后，如果要执行退出`ngx.exit`, 要清除保存的数据（ctx._private_data = nil）,否则无法退出。原因是？  
