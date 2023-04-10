
## 生成证书
[参考链接](https://www.cnblogs.com/Anker/p/6018032.html)  

### 自签CA证书
```
#生成根证书私钥(pem文件)
openssl genrsa -out root.key 2048
#生成根证书签发申请文件(csr文件)
openssl req -new -out root.csr -key root.key -subj "/C=CN/ST=myprovince/L=mycity/O=myorganization/OU=mygroup/CN=root"
#openssl req -new -out root.csr -key root.key
#自签发根证书(cer文件) 
openssl x509 -req -in root.csr -out root.crt -signkey root.key -CAcreateserial -days 3650
```
### 服务端私钥和证书
```
# create server.key
#生成服务端私钥 
openssl genrsa -out server.key 2048
#生成证书请求文件
openssl req -new -out server.csr -key server.key -subj "/C=CN/ST=myprovince/L=mycity/O=myorganization/OU=mygroup/CN=server"
#openssl req -new -out server.csr -key server.key
#使用根证书签发服务端证书 
openssl x509 -req -in server.csr -out server.crt -signkey server.key -CA root.crt -CAkey root.key -CAcreateserial -days 3650
#使用CA证书验证server端证书
openssl verify -CAfile root.crt server.crt
```
### 客户端私钥和证书
```
# create client.key
#生成客户端私钥 
openssl genrsa -out client.key 2048
#生成证书请求文件
openssl req -new -out client.csr -key client.key -subj "/C=CN/ST=myprovince/L=mycity/O=myorganization/OU=mygroup/CN=client"
#openssl req -new -out client.csr -key client.key
#使用根证书签发客户端证书 
openssl x509 -req -in client.csr -out client.crt -signkey client.key -CA root.crt -CAkey root.key -CAcreateserial -days 3650
#使用CA证书验证客户端证书
openssl verify -CAfile root.crt client.crt
```

* 默认生成的 crt, key 就是PEM 格式的  
* Common Name 要使用不同的name

## Nginx 配置
```
server {
        listen       443 ssl;
        server_name  www.yourdomain.com;
        ssl                  on;  
        ssl_certificate      /data/sslKey/server.crt;  #server公钥证书
        ssl_certificate_key  /data/sslKey/server.key;  #server私钥
        ssl_client_certificate /data/sslKey/root.crt;  #根证书，可以验证所有它颁发的客户端证书
        ssl_verify_client on;  #开启客户端证书验证  

        location / {
            root   html;
            index  index.html index.htm;
        }
    }
```
## libcurl 设置
```
curl_easy_setopt(c, CURLOPT_SSL_VERIFYPEER, 1L);
curl_easy_setopt(c, CURLOPT_SSL_VERIFYHOST, 0L);


const char *pCertFile = "/home/think/ssl2/client.crt";
const char *pPassphrase = "";
const char *pKeyType = "PEM";
const char *pKeyName = 	  "/home/think/ssl2/client.key";
const char *pCACertFile = "/home/think/ssl2/root.crt";
curl_easy_setopt(c, CURLOPT_SSLCERTTYPE, pKeyType);
curl_easy_setopt(c, CURLOPT_SSLKEYTYPE, pKeyType);
curl_easy_setopt(c, CURLOPT_SSLCERT, pCertFile);
curl_easy_setopt(c, CURLOPT_SSLKEY,  pKeyName);
curl_easy_setopt(c, CURLOPT_CAINFO,  pCACertFile);
curl_easy_setopt(c, CURLOPT_CAPATH,  "/home/think/ssl2/");
```

CURLOPT_SSL_VERIFYHOST 

## ISSU
### 文件权限
生成的key,crt 文件，注意文件权限
```
curl: (58) could not load PEM client certificate, OpenSSL error error:0200100D:system library:fopen:Permission denied, (no key found, wrong pass phrase, or wrong file format?)
```

### ee key too small
使用curl 7.74 版本报错 SSL_CTX_use_certificate:ee key too small
```
/usr/bin/curl --cert client.crt --key client.key https://10.1.7.5/test -k
curl: (58) could not load PEM client certificate, OpenSSL error error:140AB18F:SSL routines:SSL_CTX_use_certificate:ee key too small, (no key found, wrong pass phrase, or wrong file format?)
```

私钥长度太短，需要高于1024

## curl 查看证书信息
`curl -vvl https://xxx`
