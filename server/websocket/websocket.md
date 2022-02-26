

## 什么时websocket

### 使用wx 登录csdn 过程

1. 前端页面请求csdn server， 然后server 生成token，响应数据，前端页面生产二维码
2. 手机wx 扫描二维码，获得token，并传到wx 服务器上，
3. wx 服务器回调，向csdn 请求（POST）
4. CSDN 服务器通知前端页面，登录成功

第4步就使用了websockt。
此外还有 页游，比赛文字直播，

## 浏览器与服务器实时通信方式
### ajax短轮询
缺点： 造成服务器有很多的无效响应，并不实时

### 长轮询
长连接 + http请求  
缺点： 比如发一个短消息，会包上http头，有用数据占比不高

### websocket
非http 协议，

### html sse
视频推流？

## Demo

文档 rfc6455

客户端

websockt 握手协议
数据帧格式

