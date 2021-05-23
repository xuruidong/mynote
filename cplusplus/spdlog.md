# spdlog

## 特点
* 非常快
* 支持单头文件方式和预编译方式使用
* 丰富的格式化特性
* 支持异步模式
* 可自定义格式
* 单/多线程的日志记录器
* 多种日志目标
* 日志过滤
* 支持从参数和环境变量加载日志级别
* 支持回溯追踪

## 编译和使用

spdlog 可以指使用头文件添加到工程中，即可使用。编译器至少需要支持c++11。  
也可以使用预编译方式。编译方法：  
CMake 需要3.10 或以上版本
进入spdlog-1.x 目录， 执行
```
$ cd spdlog && mkdir build && cd build
$ cmake .. && make -j
```

在编译自己的工程时，添加 -DSPDLOG_COMPILED_LIB， 例如：
```
 g++ spd1.cpp -DSPDLOG_COMPILED_LIB -L. -I. -std=c++11 -lspdlog  
```

## Hello World
```
#include "spdlog/spdlog.h"
int main()
{
    //Use the default logger (stdout, multi-threaded, colored)
    spdlog::info("Hello, {}!", "World");
}

```
spdlog 提供了一种像Python 一样的字符串格式化方式。


## 输出到文件
spdlog 采用的是“包含你所需要的”方式，即你需要什么样的特性，就包含对应的头文件。spdlog 默认是输出到终端的，当你需要将日志输出到文件，需要包含头文件 `spdlog/sinks/basic_file_sink.h`  

```
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging

int main()
{
    auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
    spdlog::set_default_logger(my_logger);
    spdlog::info("Hello, {}!", "World");
    return 0;
}
```

## 滚动切割日志
使用切割日志的特性，需要包含`spdlog/sinks/rotating_file_sink.h`  
```
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

int main()
{
    auto file_logger = spdlog::rotating_logger_mt("file_logger", "logs/basic.txt", 1024 * 5, 3);
    spdlog::set_default_logger(file_logger);
    for(int i=0; i<100000; ++i)
        spdlog::info("Hello, {}!", "World");
    return 0;
}
```

## 使用工厂方法创建异步日志记录器
```
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging
#include "spdlog/async.h" //support for async logging.
#include <unistd.h>

int main()
{
   // auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
   // auto file_logger = spdlog::rotating_logger_mt("file_logger", "logs/basic.txt", 1024 * 5, 3);
   // spdlog::set_default_logger(file_logger);
    // default thread pool settings can be modified *before* creating the async logger:
    spdlog::init_thread_pool(10000, 3); // queue with 10K items and 1 backing thread.
    auto async_file = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
    for (int i = 1; i < 101; ++i)
    {
        async_file->info("Async message #{}", i);
        sleep(1);
    }
    // Under VisualStudio, this must be called before main finishes to workaround a known VS issue
    spdlog::drop_all();
    return 0;
}
```
编译时链接pthread 库。可以设置线程池的数量及队列大小。
```
PID USER      PR  NI    VIRT    RES    SHR S %CPU %MEM     TIME+ COMMAND
  3103 root      20   0  109280   5308   1104 S  0.0  0.5   0:00.00 a.out
  3104 root      20   0  109280   5308   1104 S  0.0  0.5   0:00.00 a.out
  3105 root      20   0  109280   5308   1104 S  0.0  0.5   0:00.00 a.out
  3106 root      20   0  109280   5308   1104 S  0.0  0.5   0:00.00 a.out
```

## 日志分类
```
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging

int main()
{
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/basic.txt");
    auto net_logger = std::make_shared<spdlog::logger>("net",file_sink);
    auto hw_logger  = std::make_shared<spdlog::logger>("hw", file_sink);
    auto db_logger  = std::make_shared<spdlog::logger>("db", file_sink);
    net_logger->info("Hello, {}!", "World");
    hw_logger->info("Hello, {}!", "World");
    db_logger->info("Hello, {}!", "World");
    return 0;
}
```
通过创建多个共享同一个sink 的日志记录器来添加分类标识。  

## 将日志输出到不同的目标
```
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no colors needed
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging

int main()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::warn);
    console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
    file_sink->set_level(spdlog::level::trace);

    spdlog::sinks_init_list sink_list = { file_sink, console_sink };

    spdlog::logger logger("multi_sink", sink_list.begin(), sink_list.end());
    logger.set_level(spdlog::level::debug);
    logger.warn("this should appear in both console and file");
    logger.info("this message should not appear in the console, only in the file");

    // or you can even set multi_sink logger as default logger
    spdlog::set_default_logger(std::make_shared<spdlog::logger>("multi_sink", spdlog::sinks_init_list({console_sink, file_sink})));

    spdlog::info("Hello, {}!", "World");
    return 0;
}
```
通过创建多个sink, 然后使用一个logger。  
每个sink 可以单独设置日志格式，等级。
程序的效果是在终端和文件中出现了相应的日志。  