// 模板中的名称
// Created by Percy on 2022/6/5.
//

#include "iostream"

// C++ 中名称的分类
// 受限名称 :: ->
// 依赖型名称 std::vector<T>::iterator

int a = 1;

int main()
{
    std::cout << &a << std::endl;
    std::cout << bitand a << std::endl;
    return 0;
}

// 名称查找
// 受限名称的名称查找是在一个受限作用域内部进行的，该受限作用域由一个限定的构造所决定
// 若作用域为一个类，那么查找范围可到达其基类

int x;
class B {
public:
    int i;
};

class D : public B {};
void f(D* pd)
{
    pd->i = 3;
    // D::x = 2; // Error
}

// 非受限名称的查找则由内向外逐层查找

// Q:
// 1. ADL查找机制何时会被使用？

