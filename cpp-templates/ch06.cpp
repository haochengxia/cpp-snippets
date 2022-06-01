// 模板实战
// Created by Percy on 2022/5/31.
//

// 模板的声明和定义需要在同一文件，这种组织方式为包含模型

#include "iostream"
#include "typeinfo"

template <typename T>
void print_typeof(T const&);

template <typename T>
void print_typeof(T const& x)
{
    std::cout << typeid(x).name() << std::endl;
}

// 手工实例化模板
template void print_typeof<double>(double const&);

// stack.hpp 声明
// stackdef.hpp 定义
// stackinst.cpp 显式实例化

// 另一种组织方式为分类模型，利用export实现
//export
//template <typename T>
//void print_typeof(T const&);

// 如下方定义在不同文件，也会被隐式地export
//template <typename T>
//void print_typeof(T const& x)
//{
//    std::cout << typeid(x).name() << std::endl;
//}

