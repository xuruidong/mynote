
## visual box

### 离线安装系统
在安装过程中，disable 网卡，然后选择 “Continue without network”
[参考](https://www.cnblogs.com/beilong/p/15778605.html)  

### 网络配置
```
vim /etc/netplan/******.yaml
```
```
network:
  version: 2
  renderer: networkd
  ethernets:
    eth0:  //这里是有线网卡名字，可以通过ifconfig查看获得
      dhcp4: yes //启用dhcp4
    eth1:
      addresses: [192.168.1.100/24]
      dhcp4: no   //禁用dhcp4   
      dhcp6: no
      gateway4: 192.168.1.1
      nameservers: //DNS服务器列表，多个则用逗号分开        
        addresses: [192.168.1.1,114.114.114.114]
  wifis:
    wlan0:  //这里是无线网卡名字，可以通过ifconfig查看获得    
      dhcp4: no
      dhcp6: no
      address: [192.168.2.155/24]     
      gateway4: 192.168.1.1
      nameservers:
        addresses: [192.168.1.1,8.8.8.8] 
      access-points:
        "****": //无线网络名称（SSID）
          password: "********" //无线网络密码
```
配置完成后启用配置sudo netplan apply
更多的配置案例请参考下面链接[https://netplan.io/examples/](https://netplan.io/examples/)  

### 关闭更新
ubuntu :
[disable updates from command line in Ubuntu 16.04](https://askubuntu.com/questions/1059971/disable-updates-from-command-line-in-ubuntu-16-04)  
```
systemctl stop apt-daily.timer
systemctl disable apt-daily.timer
systemctl disable apt-daily.service
systemctl stop apt-daily-upgrade.timer
systemctl disable apt-daily-upgrade.timer
systemctl disable apt-daily-upgrade.service
```

### sudo 慢
```
hname=`hostname`
echo '127.0.0.1 $hname' >> /etc/hosts
```