
cassand

安装 jdk 8
apt install openjdk-8-jdk


移除openjdk包，命令：apt-get purge openjdk*

卸载 postgresql
```
apt-GET --purge remove postgresql postgresql-8.3  postgresql-client  postgresql-client-8.3 postgresql-client-common postgresql-common  postgresql-contrib postgresql-contrib-8.3
```
或者 ``` apt-get --purge remove postgresql*```



## KongA

npm换源，用[淘宝的源](https://www.jianshu.com/p/f311a3a155ff)  





## Kong-build-tool 

### docker
CentOS 7.x 安装docker 报错
```
el7.x86_64
---> Package docker-scan-plugin.x86_64 0:0.8.0-3.el7 will be installed
---> Package libcgroup.x86_64 0:0.41-21.el7 will be installed
---> Package libseccomp.x86_64 0:2.3.1-4.el7 will be installed
--> Finished Dependency Resolution
Error: Package: 3:docker-ce-20.10.8-3.el7.x86_64 (docker-ce-stable)
           Requires: container-selinux >= 2:2.74
Error: Package: docker-ce-rootless-extras-20.10.8-3.el7.x86_64 (docker-ce-stable)
           Requires: fuse-overlayfs >= 0.7
Error: Package: docker-ce-rootless-extras-20.10.8-3.el7.x86_64 (docker-ce-stable)
           Requires: slirp4netns >= 0.4
Error: Package: containerd.io-1.4.9-3.1.el7.x86_64 (docker-ce-stable)
```

解决：
```
#进入yum 源配置文件夹
cd /etc/yum.repos.d
mv CentOS-Base.repo CentOS-Base.repo_bak

在文件顶部添加一个条目/etc/yum.repos.d/docker-ce.repo，内容如下：
[centos-extras]
name=Centos extras - $basearch
baseurl=http://mirror.centos.org/centos/7/extras/x86_64
enabled=1
gpgcheck=0
```


libcurl configure: error: one or more libs available at link-time are not available run-time

ln -s /usr/local/lib64/libssl.so.1.1 /usr/lib64/libssl.so.1.1
ln -s /usr/local/lib64/libcrypto.so.1.1 /usr/lib64/libcrypto.so.1.1


Ubuntu 重启网络
systemctl status systemd-networkd


curl wget 跳过关闭https证书验证
curl -k
wget --no-check-certificate


```bash
$ kong migrations up
Error: [Cassandra error] failed to insert cluster lock: [Write timeout] Operation timed out - received only 0 responses.

  Run with --v (verbose) or --vv (debug) for more details
```


## kong 安装

[KONG 开源API网关安装手册](https://yonglun.me/kong-install-manual/)  



init_by_lua*
发生在master进程启动阶段。这里会对数据访问层进行初始化，加载插件的代码，构造路由规则表。

1.
```
Error: [PostgreSQL error] failed to retrieve PostgreSQL server_version_num: FATAL: Ident authentication failed for user "kong"
```
vi /var/lib/pgsql/10/data/pg_hba.conf 
```
host    all             all             127.0.0.1/32            trust
```

2. command not found

```
i was trying with a wrong user on same machine,when i tried with user who installed kong solved the issue
```