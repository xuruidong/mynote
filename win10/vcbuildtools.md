
# mu_visual_cpp_build_tools_2015_update_3_x64_dvd_dfd9a39c 安装

win7 32位

出现问题：
.NET 不符合最低版本要求， 安装.net 4.5.2


证书安装：
需要将证书安装到 “受信任的根证书颁发机构”

占用空间大概 3.2G


运行 cl 命令，提示 api-ms-win-crt-runtime-l1-1-0.dll 丢失， 

解决方法： 安装 VC redit.exe ， 如果 VC redit.exe 安装失败， 安装KB2999226补丁程序，把系统更新到SP1,然后再安装 VC redit.exe  
[参考](https://zhuanlan.zhihu.com/p/161848796)  


https://blog.csdn.net/finghting321/article/details/105528436  


ucrtbased.dll  
https://blog.csdn.net/so_geili/article/details/53009680  




https://docs.microsoft.com/zh-cn/sysinternals/downloads/autoruns