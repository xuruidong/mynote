
## kcproxy + dns 一体机
环境说明：
设备ip : DEV_IP
dns forward ip: FORWARD_IP

* 用户dns 配置为 DEV_IP
* 使用iptables 将目的地址为 FORWARD_IP ,目的端口为53，协议为udp 的数据包转发到 7000端口
  `-A OUTPUT -d 204.197.191.194/32 -p udp -m udp --dport 53 -j REDIRECT --to-ports 7000`
* dns forward 请求包源地址为 DEV_IP， 做DNAT后,目的地址变成了 127.0.0.1 ，kcproxy 将其改成FORWARD_IP。 B点代理时，这个包的源地址也是 DEV_IP，代理后返回的结果，目的地址也是 DEV_IP， 源地址是 FORWARD_IP。 这个回包到达A点后， kcproxy 将这个包的源地址改为 127.0.0.1：7000,   
  ```
  [root@localhost ~]# cat /proc/net/nf_conntrack | grep 191.194  
  ipv4     2 udp      17 11 src=172.16.3.100 dst=204.197.191.194 sport=22602 dport=53 [UNREPLIED] src=127.0.0.1 dst=172.16.3.100 sport=7000 dport=22602 mark=0 zone=0 use=2
  ```
* kcproxy 收到经过DNAT 的 udp 数据包时， 不能得到真正的目的地址，需要处理。
* 





## 透明代理方式收包
使用 recvmsg + IP_RECVORIGDSTADDR 获取到数据包的真正目的地址
[Linux使用TPROXY进行UDP的透明代理](https://www.jianshu.com/p/76cea3ef249d)  
[iptables：tproxy做透明代理](https://blog.csdn.net/u011431128/article/details/77481678)  

