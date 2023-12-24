# 动态链接示例与 Makefile

该项目提供了一个简单的 C++ 动态链接示例，使用共享库。它包括两个版本的函数 (`fun`)，分别位于不同目录 (`v1` 和 `v2`) 下，每个版本都被编译成一个独立的共享库。`main.cpp` 文件动态加载并调用这些函数。

## 构建与运行

请进入项目的根目录并运行：

```
$ make
g++ -std=c++11 -Wall -shared -fPIC -o v1/fun.so v1/fun.cpp
g++ -std=c++11 -Wall -shared -fPIC -o v2/fun.so v2/fun.cpp
g++ -std=c++11 -Wall main.cpp v1/fun.so v2/fun.so -o dynamic_link_example -ldl
$ ./dynamic_link_example 
Calling v1/fun(): fun version 1
Calling v2/fun(): fun version 2
```