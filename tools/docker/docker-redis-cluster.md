# docker

## 拉取 redis 镜像
docker pull redis:4.0
如果使用最新版 redis （7.0）， efan 在连接集群时出错

## 创建容器

至少要有 3个redis 主节点，才能成功创建 cluster。

命令：
```
docker create --name redis-node1 --net=host -v /data/redis-data/node1:/data redis --cluster-enabled yes --cluster-config-file nodes-node-1.conf --cluster-node-timeout 10000 --appendonly yes --port 6371
```

创建redis容器参数解释：
     --net=host 容器和宿主机共用网络 不需要再做端口映射
     -v 创建容器数据卷
     --cluster-enabled：是否启动集群，选值：yes 、no
     --cluster-config-file 配置文件.conf ：指定节点信息，自动生成
     --cluster-node-timeout 毫秒值： 配置节点连接超时时间
     --appendonly 是否开启持久化，选值：yes、no
     --port 端口

创建 6 个容器， 三主三从。
脚本：
```
#!/bin/bash

function create_container()
{
    for ((i=1; i<7; i++)); do
        num=$i
        ((port=6370 + i))
        echo $num
        echo $port
        echo create redis-node$num
        docker create --name redis-node$num --net=host -v /data/redis-data/node$num:/data redis:4.0 --cluster-enabled yes --cluster-config-file nodes-node-$num.conf --cluster-node-timeout 10000 --appendonly yes --port $port
    done
}

create_container

```

## 启动容器
```
docker start redis-node1 redis-node2 redis-node3 redis-node4 redis-node5 redis-node6
```

## 创建集群

进入任意一个创建的redis容器，以redis-node1为例
```
docker exec -it redis-node1 /bin/bash
```
执行组件集群的命令，localhos替换成实际的主机ip
```
redis-cli --cluster create localhos:6371 localhos:6372 localhos:6373 localhos:6374 localhos:6375 localhos:6376 --cluster-replicas 1
```

参数解释
    --cluster-replicas 1： 参数后面的数字表示的是主从比例，这里的1，表示1个主节点对应1个从节点。上面创建了6个reids容器，所以主从分配就是3个主节点，3个从节点。
    注意 主节点最少3个，3个才能保证集群的健壮性。

## 测试
```
$redis-cli -h 10.0.1.100 -p 6371 -c
10.0.1.100:6371> cluster nodes
a7a47b3c38f06f5312fee0dc3ca8993ba425f3d8 10.0.1.100:6375@16375 slave 0ab282cd7a0d622e8763c4f7971aa849081c548d 0 1654157809258 1 connected
899b336af631da8d052cb941e89fc8f84beeaa83 10.0.1.100:6373@16373 master - 0 1654157811000 3 connected 10923-16383
9f780a5bd5c3885097bbd8e96fca2f93b6ddcf95 10.0.1.100:6374@16374 slave 899b336af631da8d052cb941e89fc8f84beeaa83 0 1654157808000 3 connected
c604cfa5b578ce3bce9407a8e5f490d1a239c41e 10.0.1.100:6376@16376 slave 2f972fcf6edb28124bc999b41aeb9bba9921741f 0 1654157811061 2 connected
0ab282cd7a0d622e8763c4f7971aa849081c548d 10.0.1.100:6371@16371 myself,master - 0 1654157807000 1 connected 0-5460
2f972fcf6edb28124bc999b41aeb9bba9921741f 10.0.1.100:6372@16372 master - 0 1654157810260 2 connected 5461-10922
```


# 另一个
[cankao](https://cloud.tencent.com/developer/article/1838120)  