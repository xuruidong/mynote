# mynote
my note


http://finelybook.com/?s=bpf

http://www.brendangregg.com/index.html

http://nginx.org/en/docs/


如果实在是看着不顺眼，去操作系统注册表，把 HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Profiles 这个下面的子项全部删掉，重新连接网络，网络名又会从最初的开始（看子项的值就能看到，每一个网络名都对应这里的一个子项，全部删掉不会造成什么后果，也可以一个一个删）



HKEY_CLASSES_ROOT\Directory\Background\shell\OpenWithMobaXterm\command

win10 关闭microsoft store 自动更新 （wsappx 进程占用资源高）


win10 输入法，只使用微软拼音，将shift 切换关闭，使用 Ctrl-Space



visualBox :

[vb网络配置](https://www.jianshu.com/p/e6ba699b5992)

```
sudo mount -t vboxsf E_DRIVE /mnt/e
```

禁用AppXsvc
1、组合键Win + R 输入 regedit 打开【注册表】
2、打开注册表路径：
计算机\HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Services\AppXSvc
3、双击右侧start 把3改为4重启就可以了。


========== UNISON ===========
[模式匹配参数](https://www.cnblogs.com/xiao-apple36/p/9370835.html)  
[Unison File Synchronizer 文件同步使用](https://houzw.github.io/2016/11/25/Unison-File-Synchronizer-%E6%96%87%E4%BB%B6%E5%90%8C%E6%AD%A5%E4%BD%BF%E7%94%A8/#3-2-%E8%BF%9C%E7%A8%8B%E4%BD%BF%E7%94%A8)

[WinSCP 实现批处理同步文件](https://www.jianshu.com/p/ff719480e0ef)  

目录下 `*.o` 不会同步， 子目录下的也不会同步。  `“.*”` 会同步
`ignore = Name { *.o， .* }`
忽略  " .* ",  但不能忽略 xxx/.*
`ignore = Path .*`

只能忽略 xxx/yyy/.zzz
`ignore = Path */*/.*` 

忽略tmp 目录， 但不能忽略 xxx/tmp
`ignore = Path tmp`

没什么卵用，好像和 PATH 一样
`ignore = Regex output`
`ignore = BelowPath output`


nice!
```
ignore = Name {*/output/*}
ignore = Name {\.*}
```

常用：
```
ignore = Name {*.swp, *~, *.log} 
ignore = Name {*.lib, *.a, *.la, *.lo}
ignore = Name {*.o, *.obj, *.ko, *.elf}
ignore = Name {*.ilk, *.map, *.exp}
ignore = Name {*.dll, *.so, *.so.*, *.dylib}
#ignore = Path .* 
#ignore = Path */*/.* 

#ignore = Path {*.o,*/*/output/,output} 
#ignore = Path */*.o 
#ignore = Path */output
#ignore = Regex output
#ignore = BelowPath output
ignore = Name {*/output/*}
ignore = Name {\.*}
```

[win32 GUI](https://blog.csdn.net/boysoft2002/article/details/113872254)  


### codeblocks
[如何在mingw中执行libwinpthread-1.dll的静态链接？](https://www.oomake.com/question/3849953)  

要静态链接winpthread，即使程序中未使用线程，也要将-Bstatic和--whole-archive参数传递给链接器：

g++ -o hello.exe hello.cpp -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
请注意以下事项：
* 之后应立即禁用“整个存档”选项。
* 如果您的程序实际使用了库中的符号(即您使用C++ 11中的<thread>)，则不需要执行此操作，在这种情况下，当您静态链接库时，库不会被删除。 / LI>
* 此hack适用于MinGW-w64，用于修复libwinpthread-1.dll依赖项。
