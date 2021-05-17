
## 安装

### hello world
```
stap -ve 'probe begin { log("hello systemtap!") exit() }'
```

正常情况下会输出
```
Pass 1: parsed user script and 475 library scripts using 263100virt/78868res/6460shr/72864data kb, in 280usr/600sys/959real ms.
Pass 2: analyzed script: 1 probe, 2 functions, 0 embeds, 0 globals using 264948virt/81136res/6916shr/74712data kb, in 0usr/10sys/13real ms.
Pass 3: using cached /root/.systemtap/cache/b6/stap_b621d886a1a9916f17477780a294e2c3_1012.c
Pass 4: using cached /root/.systemtap/cache/b6/stap_b621d886a1a9916f17477780a294e2c3_1012.ko
Pass 5: starting run.
hello systemtap!
Pass 5: run completed in 0usr/40sys/517real ms.
```

## 探针
我理解的探针就是观测点。如：
* begin： systemtap 会话开始
* end： systemtap 会话结束
* syscall.read: 系统调用 read() 的开始
* syscall.read.return: 系统调用 read() 的结束
* kernel.function("sys_read")：内核函数 sys_read() 的开始
* kernel.function("sys_read").return：内核函数 sys_read() 的结束
* socket.send: 发送包
* timer.ms(100): 对单一CPU每100毫秒触发一次的探针
* timer.profile：按内核始终频率对所有的CPU都触发的探针，用于采样、剖析
* process("a.out").function("foo*")： a.out 中函数名前缀为foo的函数信息
* process("a.out").statement("*@main.c:200"), a.out中文件main.c 200行处的状态

## tapset
一组相关的探针被称作 tapset。 tapset 举例：
* syscall: 系统调用
* ioblock: 块设备接口和I/O调度器
* scheduler: 内核CPU调度器事件
* memory: 进程和虚拟内存的使用
* scsi: SCSI目标事件
* networking: 网络设备事件，包括接收和传输
* tcp: TCP协议事件，包括发送和接收事件
* socket: 套接字事件

## 内置变量
可用于打印信息，常用的内置变量：
* tid()：当前线程id
* pid()： 当前进程id
* uid()：当前用户id
* execname()：当前进程名称
* cpu()：当前cpu编号
* gettimeofday_s()：秒时间戳
* get_cycles()：硬件周期计数器快照
* pp(): 探测点事件名称
* ppfunc(): 探测点触发的函数名称
* `$$var`: 上下文中存在 $var，可以使用该变量
* print_backtrace(): 打印内核栈
* print_ubacktrace(): 打印用户空间栈

## 示例
### 追踪 sock_ioctl
```
#!/usr/bin/stap

probe begin 
{
    log("begin to probe")
}

probe kernel.function("sock_ioctl")
{
    printf ("%s(%d) function_name: %s, %s\n", execname(), pid(), ppfunc(), pp())
}

probe end
{
    log("end to probe")
}
```
执行脚本 # ./ioctl.stp，再执行 ethtool ens33, 输出：
```
[root@localhost stap_test]# ./ioctl.stp
begin to probe
ethtool(6943) function_name: sock_ioctl, kernel.function("sock_ioctl@net/socket.c:928")
ethtool(6943) function_name: sock_ioctl, kernel.function("sock_ioctl@net/socket.c:928")
ethtool(6943) function_name: sock_ioctl, kernel.function("sock_ioctl@net/socket.c:928")
ethtool(6943) function_name: sock_ioctl, kernel.function("sock_ioctl@net/socket.c:928")
ethtool(6943) function_name: sock_ioctl, kernel.function("sock_ioctl@net/socket.c:928")
^Cend to probe
[root@localhost stap_test]#

```

### 追踪自己写的程序
自己实现的程序，如：
```
#include <iostream>
#include <unistd.h>

using namespace std;

void test()
{
	cout<<"hello"<<endl;
}

int main()
{
	while(1) {
		test();
		sleep(1);
	}
}
```
用 stap 脚本来追踪test函数：
```
#!/usr/bin/stap

probe begin 
{
    log("begin to probe")
}

probe process("a.out").function("*test*")
{
    printf ("%s(%d) function_name: %s, %s\n", execname(), pid(), ppfunc(), pp())
}

probe end
{
    log("end to probe")
}
```
输出：
```
begin to probe
a.out(1973) function_name: _GLOBAL__sub_I__Z4testv, process("/mnt/hgfs/stap_test/a.out").function("_GLOBAL__sub_I__Z4testv")
a.out(1973) function_name: _Z4testv, process("/mnt/hgfs/stap_test/a.out").function("_Z4testv")
a.out(1973) function_name: _Z4testv, process("/mnt/hgfs/stap_test/a.out").function("_Z4testv")
^Cend to probe
```

### 追踪信号

我曾经遇到过程序异常退出，没有core, 没有异常日志，怀疑有人开车把我的程序撞死了（kill），但是我没有证据啊，就想着如果能记录信号就好了。来来来，stap 搞起来。  
```
#!/usr/bin/stap

probe begin 
{
    log("begin to probe")
}

probe end
{
    log("end to probe")
}

probe signal.send
{
	printf("Signal sent %s from %s(%d) to %s\n", sig_name, execname(), sig_pid, pid_name);
}
```
执行 killall a.out 杀死进程， 然后stap 脚本会打印相关信号的情况    
```
begin to probe
Signal sent SIGTERM from killall(3731) to a.out
Signal sent SIGCHLD from killall(2062) to bash
Signal sent SIGCHLD from a.out(1937) to bash
^CSignal sent SIGINT from kworker/1:1(3727) to stapio
Signal sent SIGINT from kworker/1:1(3447) to signal.stp
Signal sent SIGTERM from signal.stp(3727) to stapio
end to probe
```