# mynote
my note


http://finelybook.com/?s=bpf

http://www.brendangregg.com/index.html

http://nginx.org/en/docs/


如果实在是看着不顺眼，去操作系统注册表，把 HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Profiles 这个下面的子项全部删掉，重新连接网络，网络名又会从最初的开始（看子项的值就能看到，每一个网络名都对应这里的一个子项，全部删掉不会造成什么后果，也可以一个一个删）



HKEY_CLASSES_ROOT\Directory\Background\shell\OpenWithMobaXterm\command

win10 关闭microsoft store 自动更新 （wsappx 进程占用资源高）


win10 输入法，只使用微软拼音，将shift 切换关闭，使用 Ctrl-Space

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

visualBox :

[vb网络配置](https://www.jianshu.com/p/e6ba699b5992)