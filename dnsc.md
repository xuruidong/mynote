
## hash 表使用流程

* 添加节点： 先判断是否存在相同域名得节点，存在则<b><font color=red>更新</font></b>；不存在，先从free_list 中取节点，添加到hash 表；如果free_list 中没有可用节点，将 time_list 的最前一个节点取下使用



### node 节点， 可能会
* 【更新node】free_list 为空，从time_list 取下node，更新内容
* 【删除node】从time_list取下，hash 表上取下，放入free_list
* 更新 time_list 位置（此时加了写锁，所以相当于是串行的）
* 【更新node】response 回来时，更新node
* 并行读取 node 的内容。 读取过程中，需要更新 node->response.last_request_time,  node->response.a_record_cycle_id, node->response.repeat_request_cnt++  三个变量

### 增加索引计数
1. 索引变量为原子变量
2. 读取node 内容时，计数+1， 读取完毕后 -1。 （**+1 操作要在锁内执行**）
3. 需要从time_list 取下时，如果索引计数不为0， 则检查下一个node 。_如果+1 操作不在锁内执行，此时会出现的情况，刚检查时计数为0， 然后在从链表取下，更新内容时计数被其他线程+1，_
4. 【删除node】从time_list取下，hash 表上取下，放入free_list ,操作前  检查计数是否为0， ~~不是0不能操作。 记下异常的节点，重试~~ **等索引计数变为0** 再删除
5. 【更新node】response 回来需要更新node 时，先加写锁，**并且要等索引计数变为0**，再更新node

## 问题
1. 处理响应包，每次都要更新hash 表节点内容， （应该没问题）


## 配置
```
[ifcfg]
DevName=veth0               //dpdk网卡名称
HdAddr=6c:92:bf:24:1f:14    //dpdk网卡硬件地址
IpAddr=172.100.100.2        //dpdk网卡ip
IpMask=255.255.255.252      //dpdk网卡掩码
Gateway=172.100.100.1       //dpdk网卡网关
ListenPort=53               //DNS服务端口
RecursionPort=54            //DNS递归时使用的端口
ServiceIp=172.0.3.155       //服务地址  
```
* ServiceIp 是anycast 对外服务地址，机器上要在 lo 上配这个地址
* 当用户请求到达dnsc, 未命中缓存，则将数据包发送到kni 接口上，一般是交给BIND 处理，所以这个数据包的目的地址是虚拟网卡地址（配置成本机其他接口的地址可以吗？）。这些地址配置在 dnscache.xml 中

```
<Config>
	<TcpDns enable="1" />

	<ClientPool>
		<Node startaddr="0.0.0.1" endaddr="255.255.255.255" flag="1" />
	</ClientPool>
		
	<DnsServerList localhost="1">
		<Node ip="172.100.100.2" port="53" hdaddr="bc:62:0e:4e:cc:26"/>
	</DnsServerList>
</Config>
```
+ 如果bind 服务在本机 （localhost="1"）， 源地址还是客户端地址，发送给kni
+ 如果bind 服务不在本机，源IP地址是虚拟网卡地址，源MAC 地址是虚拟网卡mac 地址，目的 MAC 是 dnscache.xml 中的配置。 数据包直接从网卡发出去  



## dpdk-20.08 编译

### 升级内核到3.19

```
rpm -Uvh kernel-ml-3.19.3-1.el7.elrepo.x86_64.rpm
rpm -Uvh kernel-ml-devel-3.19.3-1.el7.elrepo.x86_64.rpm
```
查看可用内核
cat /boot/grub2/grub.cfg |grep menuentry

设置开机从新内核启动
grub2-set-default 'CentOS Linux (3.19.3-1.el7.elrepo.x86_64) 7 (Core)'  

查看内核启动项
grub2-editenv list  

### igb_uio 和 kni module
DPDK已经建议使用vfio-pci, 默认不会编译出 igb_uio 和 kni模块， 需要在 dpdk-20.08/x86_64-native-linuxapp-gcc/.config 中修改设置 
```
CONFIG_RTE_EAL_IGB_UIO=y
CONFIG_RTE_KNI_KMOD=y
```
 编译后在 dpdk-20.08/x86_64-native-linuxapp-gcc/kmod 会出现模块 

加载驱动
```
modprobe uio
insmod kmod/igb_uio.ko
```

### 使用 dpdk-setup.sh 

### 使用 meson 和 ninja
```
meson build
ninja -C build
```




[Linux平台上DPDK入门指南](https://dpdk-docs.readthedocs.io/en/latest/linux_gsg/index.html)  


iperf 发送长度 100 的包，最大流量700Mbps   


[linux下网卡bonding配置](https://www.cnblogs.com/huangweimin/articles/6527058.html) 