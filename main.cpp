#include <dlfcn.h>
#include <iostream>

typedef const char* (*fun_ptr)();

int main() {
    // 打开 v1 版本的共享库
    void* handle_v1 = dlopen("v1/fun.so", RTLD_LAZY);
    if (!handle_v1) {
        std::cerr << "Cannot open v1/fun.so: " << dlerror() << std::endl;
        return 1;
    }
    fun_ptr fun_v1 = reinterpret_cast<fun_ptr>(dlsym(handle_v1, "_Z3funv"));

    // 打开 v2 版本的共享库
    void* handle_v2 = dlopen("v2/fun.so", RTLD_LAZY);
    if (!handle_v2) {
        std::cerr << "Cannot open v2/fun.so: " << dlerror() << std::endl;
        return 1;
    }
    fun_ptr fun_v2 = reinterpret_cast<fun_ptr>(dlsym(handle_v2, "_Z3funv"));

    // 调用并输出两个版本的函数
    std::cout << "Calling v1/fun(): " << fun_v1() << std::endl;
    std::cout << "Calling v2/fun(): " << fun_v2() << std::endl;

    // 关闭共享库
    dlclose(handle_v1);
    dlclose(handle_v2);

    return 0;
}
