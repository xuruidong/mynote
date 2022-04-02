
# C/C++ 中的宏

## c++ std
[Macro Symbol Index](https://en.cppreference.com/w/cpp/symbol_index/macro)  
[Macro Symbol Index](https://en.cppreference.com/w/c/symbol_index/macro)  

## GNU C
'''
__PRETTY_FUNCTION__

'''


## MSVC

'''
__FUNCTION__   // with class 
__FUNCDNAME__ and __FUNCSIG__

'''


## 不确定编译器
'''
The closest thing there's is to call typeid(your_class).name() - but this produces compiler specific mangled name.

To use it inside class just typeid(*this).name()


'''


c++20 支持 [source_location](https://zh.cppreference.com/w/cpp/utility/source_location)  

