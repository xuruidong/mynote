
# docker

```
#docker run -itd --name efan_end -p 7700:6600 --privileged -v /home/xuruidong/work/efan:/data/efan -w /data/efan centos:centos7 /bin/bash
docker run -itd --name efan_end -p 7700:6600 --privileged -v /home/xuruidong/work/efan:/data/efan -w /data/efan efan /bin/bash

#docker run -itd --name efan_end -p 7700:6600 -v /home/xuruidong/work/efan:/data/efan -w /data/efan centos:centos7 /bin/bash -c 'bin/efan_end /data/efan/conf/efan_end.conf'
```

## 以非 Root 用户身份执行 Docker
```
sudo usermod -aG docker $USER
```
登出，并且重新登录，以便用户组会员信息刷新 

查看 `docker.sock` 的读写权限：
```
$ll /var/run/docker.sock
srw-rw---- 1 root docker 0 Jan 19  2023 /var/run/docker.sock
```

查看 docker 用户组：
 ```
sudo cat /etc/group | grep docker
docker:x:990:user1,user2
```

