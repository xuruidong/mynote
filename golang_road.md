# 踩在 golang 大道的坑上
--- 酱油在手，低头猛走

## 包安装

1. cannot find package "golang.org/x/sys/windows" in any of:
        D:\Go\src\golang.org\x\sys\windows (from $GOROOT)
        C:\Users\Think\go\src\golang.org\x\sys\windows (from $GOPATH)

解决方案： github上的镜像库放入GOPATH下即可
git clone https://github.com/golang/sys.git
放到 C:\Users\Think\go\src\golang.org\x\， GOPATH=C:\Users\Think\go 

## xml
变量名开头大写

