

## 编译问题

```
In file included from /usr/include/linux/ip.h:20:
/usr/include/linux/types.h:5:10: fatal error: 'asm/types.h' file not found
#include <asm/types.h>
```

解决
```
apt-get install -y gcc-multilib
```


```
ip link set dev [device name] xdp obj xdp-drop-world.o sec [section name]
```
sec [section name]就是上文提到的通过Section来指定程序入口
device name是本机某个网卡设备的名称，可以通过ip a查看本机所有的网卡设备。一般可以选取本机对外的IP所在的网卡设备。

ip link set dev enp0s3 xdp obj prog_kern.o sec xdp_drop

通过如下命令卸载掉xdp函数

[root@localhost xdp]#ip link set dev eno1 xdp off


### 内核编译选项查看

```
cat /boot/config-$(uname -r)
```



 tcpdump -i any -nn "tcp[tcpflags] & (tcp-syn) != 0" and host 10.16.77.235




 ## clang 12 在centos 7 上安装

 ### 
```
[ 50%] Building CXX object projects/lld/MachO/CMakeFiles/lldMachO2.dir/UnwindInfoSection.cpp.o
In file included from /home/xuruidong/clang/llvm-12.0.0/projects/lld/MachO/UnwindInfoSection.cpp:9:
/home/xuruidong/clang/llvm-12.0.0/projects/lld/MachO/UnwindInfoSection.h:15:10: fatal error: mach-o/compact_unwind_encoding.h: No such file or directory
   15 | #include "mach-o/compact_unwind_encoding.h"
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make[2]: *** [projects/lld/MachO/CMakeFiles/lldMachO2.dir/build.make:90: projects/lld/MachO/CMakeFiles/lldMachO2.dir/UnwindInfoSection.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:32538: projects/lld/MachO/CMakeFiles/lldMachO2.dir/all] Error 2
make: *** [Makefile:156: all] Error 2
```
将 llvm-12.0.0/projects/libunwind/include/mach-o  拷贝到 ldd/MachO/

 ### 
 ```
 CMake Error at projects/libcxx/src/cmake_install.cmake:88 (file):
  file RPATH_CHANGE could not write new RPATH:

    

  to the file:

    /usr/local/clang-12/lib/libc++.so

Call Stack (most recent call first):
  projects/libcxx/cmake_install.cmake:56 (include)
  projects/cmake_install.cmake:51 (include)
  cmake_install.cmake:76 (include)
```
cmake-3.22.0 
换 cmake-3.24.0


安装libelf     yum install devtoolset-11-elfutils*
要安装 glic-static 


```
[root@w-live05 rpmbuild]# gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/opt/rh/devtoolset-11/root/usr/libexec/gcc/x86_64-redhat-linux/11/lto-wrapper
Target: x86_64-redhat-linux
Configured with: ../configure --enable-bootstrap --enable-languages=c,c++,fortran,lto --prefix=/opt/rh/devtoolset-11/root/usr --mandir=/opt/rh/devtoolset-11/root/usr/share/man --infodir=/opt/rh/devtoolset-11/root/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-gcc-major-version-only --with-linker-hash-style=gnu --with-default-libstdcxx-abi=gcc4-compatible --enable-plugin --enable-initfini-array --with-isl=/builddir/build/BUILD/gcc-11.2.1-20220127/obj-x86_64-redhat-linux/isl-install --enable-gnu-indirect-function --with-tune=generic --with-arch_32=x86-64 --build=x86_64-redhat-linux
Thread model: posix
Supported LTO compression algorithms: zlib
gcc version 11.2.1 20220127 (Red Hat 11.2.1-9) (GCC) 
```

