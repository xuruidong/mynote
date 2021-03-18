# openvpn 配置

[参考](https://i4t.com/4481.html?__cf_chl_jschl_tk__=41c04c14438479e207a0d7fb3f906ae225f14120-1609222403-0-AXi7ltXaTMYzrzveMSOlmB_qhINy8VeKYovh74FL4hld-_nEQImzDDcAzc0hppvxSmzYOF1aTxv6RSZHh_404OwSI1Vy9LhH26RhKOmvvD2rkqPpYE2F71Xe1gpx5iwH49-iFJns78Et-Y0tuMqcnynWWK1mWLFonpB-LDXEWd5li9QCnbVK75L-i8uM5T5kO_4Knpx704jiIAR0vHorI13jl1y8JhJFp07wvVtgnSZdBDMlkPV9NmUoAJe_6NFi65JHuDHS90d9c9pnY2B8mzSlKph4HPJDEnY0jl3k_1kPN2ON4ylaKBs8rkjOoFGCug)  

## 环境
Ubuntu

## 安装
### 源码安装方式


### apt-get 安装
1. sudo apt-get -y install openvpn libssl-dev openssl

2. 查看openvpn 相关的文件  
dpkg -L openvpn  

其中有相关配置的模板 
```
/usr/share/doc/openvpn/examples/sample-keys/server.key

```

3. 安装 easy-rsa
  sudo apt-get -y install easy-rsa

  dpkg -L easy-rsa 
  ```
  /usr/share/man/man1/make-cadir.1.gz
/usr/share/easy-rsa
/usr/share/easy-rsa/pkitool
/usr/share/easy-rsa/whichopensslcnf
/usr/share/easy-rsa/list-crl
/usr/share/easy-rsa/revoke-full
/usr/share/easy-rsa/clean-all
/usr/share/easy-rsa/build-inter
/usr/share/easy-rsa/build-ca
/usr/share/easy-rsa/build-key-pass
/usr/share/easy-rsa/openssl-1.0.0.cnf
/usr/share/easy-rsa/build-key-pkcs12
/usr/share/easy-rsa/openssl-0.9.6.cnf
/usr/share/easy-rsa/inherit-inter
/usr/share/easy-rsa/build-dh
/usr/share/easy-rsa/sign-req
/usr/share/easy-rsa/build-req-pass
/usr/share/easy-rsa/build-key
/usr/share/easy-rsa/build-key-server
/usr/share/easy-rsa/openssl-0.9.8.cnf
/usr/share/easy-rsa/vars
/usr/share/easy-rsa/build-req
/usr/share/doc
/usr/share/doc/easy-rsa
/usr/share/doc/easy-rsa/README-2.0.gz
/usr/share/doc/easy-rsa/copyright
/usr/share/doc/easy-rsa/changelog.Debian.gz
/usr/share/doc/easy-rsa/README.Debian

  ```


## 证书制作

将 /usr/share/easy-rsa 拷贝到 /etc/openvpn, 
### 制作CA证书
编辑vars 文件  
vim /etc/openvpn/vars  
```
# These are the default values for fields
# which will be placed in the certificate.
# Don't leave any of these fields blank.
export KEY_COUNTRY="CN"
export KEY_PROVINCE="BJ"
export KEY_CITY="SanFrancisco"
export KEY_ORG="Fort-Funston"
export KEY_EMAIL="me@myhost.mydomain"
export KEY_OU="MyOrganizationalUnit"

# X509 Subject Field
export KEY_NAME="EasyRSA"

```
vars文件主要用于设置证书的相关组织信息，根据实际情况修改，也可以不修改。其中export KEY_NAME=”EasyRSA”这个要记住下，我们下面在制作Server端证书时，会使用到。  
然后使用source vars命令使其生效  
source vars  
执行 clean-all 命令将当前目录下的 keys 文件
./clean-all  
制作CA证书  
./build-ca  
```
Can't load /root/.rnd into RNG
140135933149632:error:2406F079:random number generator:RAND_load_file:Cannot open file:../crypto/rand/randfile.c:88:Filename=/root/.rnd
Generating a RSA private key
...............................................................................................+++++
.....................+++++
writing new private key to 'ca.key'
-----
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [CN]:
State or Province Name (full name) [BJ]:
Locality Name (eg, city) [SanFrancisco]:
Organization Name (eg, company) [Fort-Funston]:
Organizational Unit Name (eg, section) [MyOrganizationalUnit]:
Common Name (eg, your name or your server's hostname) [Fort-Funston CA]:
Name [EasyRSA]:
Email Address [me@myhost.mydomain]:
```

如果报错 ‘No /etc/openvpn/easy-rsa/openssl.cnf file could be found’， 可以拷贝 /etc/openvpn/easy-rsa/openssl-1.0.0.cnf  为 openssl.cnf

此时在keys 下生成了 ca.crt  ca.key， ca.crt 就是 ca证书。把该CA证书的ca.crt文件复制到openvpn的启动目录/etc/openvpn下

### 制作 server 证书
./build-key-server EasyRSA
其中 EasyRSA 就是 vars 中的 KEY_NAME。
遇到提示，输入 y  
```
Certificate is to be certified until Mar  7 07:07:07 2031 GMT (3650 days)
Sign the certificate? [y/n]:y


1 out of 1 certificate requests certified, commit? [y/n]y
Write out database with 1 new entries
Data Base Updated

```
在keys下生成 EasyRSA.crt  EasyRSA.csr  EasyRSA.key.  
现在再为服务器生成加密交换时的Diffie-Hellman文件  
./build-dh  
之后在keys 下生成了 dh2048.pem  

把vpnilanni.crt、vpnilanni.key、dh2048.pem复制到/etc/openvpn/目录下

## 制作 client 端证书
./build-key think  
之后在keys 下生成了 think.crt, think.key, think.csr  
如果你想快速生成用户证书不需要手工交互的话，可以使用如下命令：

./build-key –batch test1

## server 配置
复制 openvpn 自带模板 
cp /usr/share/doc/openvpn/examples/sample-config-files/server.conf.gz /etc/openvpn/  
解压 gizp -d server.conf.gz  
配置 server.conf  
```

```
* 修改协议
* 修改server证书为 EasyRSA.crt,  key 为EasyRSA.key  
* dh2048.pem  

启动  

## 配置Client端




windows  
netsh interface ipv4 show subinterfaces  


netsh interface ipv4 set subinterface "本地连接" mtu=1500 store=persistent  



