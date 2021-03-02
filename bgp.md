# bgp

[参考](https://blog.csdn.net/achejq/article/details/51886732)

* 安装quagga
`yum install quagga`

* 关闭或设置SELinux, `setsebool -P zebra_write_config 1`
* 配置Zebra来管理BGP路由器的网络接口
  通过创建一个Zebra配置文件和启用日志记录来开始第一步。
  `cp /usr/share/doc/quagga-XXXXX/zebra.conf.sample /etc/quagga/zebra.conf`
* 启动zebra
  `systemctl start zebra`
  开机启动 `systemctl enable zebra`

### vtysh
Quagga提供了一个叫做vtysh特有的命令行工具。可以输入与路由器厂商(例如Cisco和Juniper)兼容和支持的命令。

#### 启动vtysh shell 
`vtysh`
提示将被改成该主机名，这表明你是在vtysh shell中。

#### 为Zebra配置日志文件
```
cpe-172-90-90-6.socal.res.rr.com# configure terminal
cpe-172-90-90-6.socal.res.rr.com(config)# log file /var/log/quagga/quagga.log
cpe-172-90-90-6.socal.res.rr.com(config)# exit
```
永久保存：
```
cpe-172-90-90-6.socal.res.rr.com# write
Building Configuration...
Configuration saved to /etc/quagga/zebra.conf
[OK]
```
#### 在可用的接口上配置对等的IP地址
##### 显示接口信息
` show interface`
```
localhost.localdomain# show interface
Interface eth8 is up, line protocol detection is disabled
  index 2 metric 1 mtu 1500
  flags: <UP,BROADCAST,RUNNING,MULTICAST>
  HWaddr: 90:e6:ba:1f:df:52
  inet 10.0.110.192/24 broadcast 10.0.110.255
  inet6 fe80::92e6:baff:fe1f:df52/64
Interface eth9 is up, line protocol detection is disabled
  index 3 metric 1 mtu 1500
  flags: <UP,BROADCAST,RUNNING,MULTICAST>
  HWaddr: 90:e6:ba:1f:dd:a0
  inet6 fe80::92e6:baff:fe1f:dda0/64
Interface lo is up, line protocol detection is disabled
  index 1 metric 1 mtu 16436
  flags: <UP,LOOPBACK,RUNNING>
  inet 127.0.0.1/8
  inet6 ::1/128
```
配置 eth8， 使用默认的IP地址，暂时不进行配置试试。

配置 eth9,
```
localhost.localdomain# configure terminal
localhost.localdomain(config)# interface eth9
localhost.localdomain(config-if)# ip address 200.200.1.1/24
localhost.localdomain(config-if)# description "test ip from provider A network"
localhost.localdomain(config-if)# no shutdown
localhost.localdomain(config-if)# exit
localhost.localdomain(config)# exit
```

再次查看接口`show interface`
显示接口描述：
`show interface description`

确认无误，进行保存 `write`

同样地，在路由器B进行配置。


## BGP对等配置和前缀设置

### 1. 准备bgpd 配置文件
`cp /usr/share/doc/quagga-XXXXXXX/bgpd.conf.sample /etc/quagga/bgpd.conf`


### 2. 启动bgpd
`systemctl start bgpd`

### 3. 确定当前没有已经配置的BGP会话
```
# vtysh
localhost.localdomain# show running-config
```
此时可能会看到一个AS号为7675的BGP会话，不需要此会话将其删除。
```
localhost.localdomain# configure terminal
localhost.localdomain(config)# no router bgp 7675
localhost.localdomain(config)# router bgp 100
localhost.localdomain(config-router)# no auto-summary
localhost.localdomain(config-router)# no synchronization
localhost.localdomain(config-router)# neighbor 10.0.110.34 remote-as 200
localhost.localdomain(config-router)# neighbor 10.0.110.34 description "provider B"
localhost.localdomain(config-router)# exit
localhost.localdomain(config)# exit
localhost.localdomain# write
```
路由器B将用同样的方式来进行配置:
```
cpe-172-90-90-6.socal.res.rr.com# configure terminal
cpe-172-90-90-6.socal.res.rr.com(config)# no router bgp 7675
cpe-172-90-90-6.socal.res.rr.com(config)# router bgp 200
cpe-172-90-90-6.socal.res.rr.com(config-router)# no auto-summary
cpe-172-90-90-6.socal.res.rr.com(config-router)# no synchronization
cpe-172-90-90-6.socal.res.rr.com(config-router)# neighbor 10.0.110.192 remote-as 100
cpe-172-90-90-6.socal.res.rr.com(config-router)# neighbor 10.0.110.192 description "provider A"
cpe-172-90-90-6.socal.res.rr.com(config-router)# exit
cpe-172-90-90-6.socal.res.rr.com(config)# exit
cpe-172-90-90-6.socal.res.rr.com# write

```
当相关的路由器都被配置好，两台路由器之间的对等将被建立.
运行 `show ip bgp summary`来确认对等建立。

### 4. 配置前缀通告
A:
```
localhost.localdomain# configure terminal
localhost.localdomain(config)# router bgp 100
localhost.localdomain(config-router)# network 100.100.0.0/22
localhost.localdomain(config-router)# exit
localhost.localdomain(config)# exit
localhost.localdomain# write
```

B:
```
cpe-172-90-90-6.socal.res.rr.com(config)# router bgp 200
cpe-172-90-90-6.socal.res.rr.com(config-router)# network 200.200.0.0/22
cpe-172-90-90-6.socal.res.rr.com(config-router)# exit
cpe-172-90-90-6.socal.res.rr.com(config)# exit
cpe-172-90-90-6.socal.res.rr.com# write

```

### 5. 测试前缀通告




---
```
socket(AF_NETLINK, SOCK_RAW, NETLINK_AUDIT) = 5
sendmsg(5, {msg_name(12)={sa_family=AF_NETLINK, pid=0, groups=00000000}, msg_iov(2)=[{"\25\0\0\0d\4\1\0\0\0\0\0\0\0\0\0", 16}, {"exit\0", 5}], msg_controllen=0, msg_flags=0}, 0) = 21
close(5)                            
```
