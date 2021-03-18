# 踩在 golang 大道的坑上
--- 酱油在手，低头猛走

## 包安装

1. cannot find package "golang.org/x/sys/windows" in any of:
        D:\Go\src\golang.org\x\sys\windows (from $GOROOT)
        C:\Users\Think\go\src\golang.org\x\sys\windows (from $GOPATH)

解决方案： github上的镜像库放入GOPATH下即可
git clone https://github.com/golang/sys.git
放到 C:\Users\Think\go\src\golang.org\x\， GOPATH=C:\Users\Think\go 

2. 
```
go get github.com/mdlayher/netlink
# cd .; git clone -- https://github.com/josharian/native C:\Users\Think\go\src\github.com\josharian\native
Cloning into '/c/Users/Think/go/src/github.com/josharian/native'...
fatal: unable to access 'https://github.com/josharian/native/': OpenSSL SSL_read: Connection reset by peer, errno 104
package github.com/josharian/native: exit status 128
unrecognized import path "golang.org/x/net/bpf": https fetch: Get "https://golang.org/x/net/bpf?go-get=1": dial tcp 216.239.37.1:443: connectex: A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
```

执行 git config --global --unset http.proxy 
git config --global --unset https.proxy

```
go get github.com/mdlayher/netlink
unrecognized import path "golang.org/x/net/bpf": https fetch: Get "https://golang.org/x/net/bpf?go-get=1": dial tcp 216.239.37.1:443: connectex: A connection attempt failed because the connected party did not properly respond after a period of time, or established connection failed because connected host has failed to respond.
```

```
 git clone https://github.com/golang.org/x/net/bpf
Cloning into 'bpf'...
fatal: unable to access 'https://github.com/golang.org/x/net/bpf/': OpenSSL SSL_read: Connection reset by peer, errno 104
```
git config --global http.sslVerify "false"
```
git clone https://github.com/golang.org/x/net/bpf
Cloning into 'bpf'...
fatal: unable to access 'https://github.com/golang.org/x/net/bpf/': Failed to connect to github.com port 443: Connection timed out
```


## env
```
go env -w GOPROXY=https://goproxy.io,direct
# Set environment variable allow bypassing the proxy for selected modules
go env -w GOPRIVATE=*.corp.example.com
go env -w GO111MODULE=on
```

## go module

go mod init xxx
go mod tidy

## xml
变量名开头大写

