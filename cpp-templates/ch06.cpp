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