// 深入模板基础
// Created by Percy on 2022/6/1.
//

#include "iostream"
#include "stack"

//// C++ 两种基本类型模板：类模板和函数模板
//
//template <typename T>
//class List {
//public:
//    template<typename T2>
//    List(List<T2> const&);
//};
//
//template <typename T>
//template <typename T2>
//List<T>::List(List<T2> const& b) {}
//
//// 联合（Union）模板，往往被看作类模板的一种
//template <typename T>
//union AllocChunk {
//    T object;
//    unsigned char bytes[sizeof(T)];
//};
//
//// 函数模板声明也可以具有缺省调用实参
//template <typename T>
//void report_top (Stack<T> const&, int number=10);
//
//template <typename T>
//void fill(Array<T>*, const& = T()); // 缺省调用实参可以依赖于模板参数， 如果fill被调用的时候总是提供了第二个参数，就不会实例化这个缺省实参，没有这个缺省构造函数也可以
//
//// 模板的链接，名字冲突问题
////int C;
////class C; // OK
////
////int X;
////template <typename T>
////class X; // Error! 模板的名字所属作用域下是唯一的，除了函数模板重载情况，特别地，类模板不能和另外一个实体共享一个名称
//
//extern "C++" template <typename T>
//void normal(); // 链接规范可缺省，模板不能具有C链接
//
//// 存在三种模板参数
//// - 类型参数
//// - 非类型参数
//// - 模板的模板参数 模板的模板实参必须是一个类模板，实际上struct和union也可以
//
//template<typename T> RT1 test(typename  T::X const*);
//template<typename T> RT2 test(...); // 省略号参数是最弱的绑定类型

// SFINA 替换失败并非错误 substitution failure is not an error，允许试图创建无效的类型，但是并不允许试图计算无效的表达式

//template <int I> void f(int (&)[24 / (4-I)]);
//template <int I> void f(int (&)[24 / (4+I)]);
//
//int main()
//{
//    &f<4>; // Error，替换后除数为0
//}
//
//template <int N> int g() { return N; }
//template <int* P> int g() { return *P; }
//
//int main()
//{
//    return g<1>(); // 1不能绑定到int*参数，但是因为SFINA OK
//}

// 有一些类型不能用作模板的类型实参
// - 局部类和局部枚举
// - 未命名的class类型或者未命名的枚举类型，但typedef声明给出的未命名类型和枚举是可以作为模板实参的

// 有些常值不能作为有效的非类型实参
// 空指针变量 浮点型值 字符串
template<typename T, T nontype_param>
class C;

int a[10];

int main()
{
    std::cout << &a[0] << std::endl;
    std::cout << a[0] << std::endl;
    C<int*, a>* ok;
//    C<int*, &a[0]>* err; // 单一数组元素的地址
    return 0;
}



// Q:
// 1. 为什么字符串不能作为非类型实参？


