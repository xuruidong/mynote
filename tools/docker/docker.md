
# docker

```
#docker run -itd --name efan_end -p 7700:6600 --privileged -v /home/xuruidong/work/efan:/data/efan -w /data/efan centos:centos7 /bin/bash
docker run -itd --name efan_end -p 7700:6600 --privileged -v /home/xuruidong/work/efan:/data/efan -w /data/efan efan /bin/bash

#docker run -itd --name efan_end -p 7700:6600 -v /home/xuruidong/work/efan:/data/efan -w /data/efan centos:centos7 /bin/bash -c 'bin/efan_end /data/efan/conf/efan_end.conf'
```