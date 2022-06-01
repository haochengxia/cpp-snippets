// 模板术语
// Created by Percy on 2022/6/1.
//

#include "string"

// 实例化模板得到的实体即为特化
// 显示特化 -> 手工实例化
template <typename T1, typename T2>
class MyClass {
private:
    T1 elem1;
    T2 elem2;
};

template<>
class MyClass<std::string, float> {
private:
    std::string elem1;
    float elem2;
};

// 还有仍然具有模板参数的特化被称为局部特化

// 声明 declaration 和 定义 definition
// 声明是一种C++构造，声明引入（或重新引入）一个名称到某个C++作用域中。宏定义和goto有名称但是不属于声明

class C;
void f(int p);
extern int v;

// 确定了构造的细节，或对变量而言分配了内存空间，声明就变成了定义
//class C {};
//void f(int p) {
//    std::cout << p << std::endl;
//}
//
//extern int v = 1;
//int w; // 没有extern的全局变量，也是定义

template <typename T, int N>
class ArrayInClass {
public:
    T array[N];
};

template <typename T>
class Dozen {
public:
    ArrayInClass<T, 12> contents;
};





