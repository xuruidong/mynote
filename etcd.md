
#
etcd采用的是MVCC来进行多版本并发控制，会存储数据的每一次变化，如果不进行压缩(删除)则空间会越变越大。
etcd的数据库空间配额大小默认限制为2G，当数据达到2G的时候就不允许写入。



## 修改数据库空间配额

* 修改systemd文件
```
# cat /etc/systemd/system/etcd.service 
......
--quota-backend-bytes=4096000000 # 这里单位是字节
......
```

* 命令行选项

etcd社区建议db大小不超过8G


## 数据备份

https://www.cnblogs.com/hsyw/p/15652417.html

## 手动压缩

```
# 获取最新revision，并压缩
etcdctl compact `(etcdctl endpoint status --write-out="json" | egrep -o '"revision":[0-9]*' | egrep -o '[0-9].*')`
# 对集群所有节点进行碎片整理
etcdctl defrag --cluster
```

## 开启自动压缩

etcd server 提供了配置压缩模式和保留时间的参数：
```
--auto-compaction-retention '0'
Auto compaction retention length. 0 means disable auto Compaction.
--auto-compaction-mode 'periodic'
Interpret 'auto-Compaction-retention' one of: periodic|revision.
```
auto-compaction-mode 为 periodic 时，它表示启用时间周期性压缩，auto-compaction-retention 为保留的时间的周期，比如 1h。
auto-compaction-mode 为 revision 时，它表示启用版本号压缩模式，auto-compaction-retention 为保留的历史版本号数，比如 10000。
e.g.
```
--auto-compaction-mode=periodic --auto-compaction-retention=30m
```
```
--auto-compaction-mode=revision --auto-compaction-retention=1000
```