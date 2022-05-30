// 函数模板
// Created by Percy on 2022/5/30.
//

template <typename T>
inline T const& max (T const& a, T const& b)
{
    return a < b ? b : a;
}

template <typename RT, typename T1, typename T2>
inline RT max1 (T1 const& a, T2 const& b)
{
    return a < b ? b : a;
}

// 这里模板参数为T，模板参数语法如下：
// template < 用逗号隔开的参数列表 >
// 例中参数列表为typename T，其中typename为关键字，T为模板参数（类型参数）

// 关键字class同样可以定义类型参数
// template <class T>
// inline T const& max (T const& a, T const& b)
// {
//     return a < b ? b : a;
// }

#include "iostream"
#include "string"

int main()
{
    int i = 42;
    std::cout << "max(7, i) : "<< ::max(7, i) << std::endl;

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1, f2) : "<< ::max(f1, f2) << std::endl;

    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "max(s1, s2) : "<< ::max(s1, s2) << std::endl;

    // type cast
    std::cout << "max(static_cast<double>(4), 4.2) : " << ::max(static_cast<double>(4), 4.2) << std::endl;
    std::cout << "max<double>(4, 4.2) : " << ::max<double>(4, 4.2) << std::endl;

    // return type
    std::cout << "max1<double>(4, 4.2) : " << ::max1<double>(4, 4.2) << std::endl;

    return 0;
}

// 上面代码中max()模板被实例化了3次，即用具体类型代替模板参数 (T -> int, T -> double, T -> std::string)。

// 重载函数模板

inline int const& max (int const& a, int const& b)
{
    return a > b? b : a;
}

template<typename T>
inline T const& max (T const& a, T const& b, T const& c)
{
    return ::max(::max(a, b), c);
}

//int main()
//{
//    std::cout << ::max(7, 42, 68) << std::endl;
//    std::cout << ::max('a', 42.7) << std::endl; // invoke int const& max (int const& a, int const& b)
//}
// 因为模板不允许自动类型转化，最后一行调用的为非模板函数
// 此外：函数的所有重载版本声明都应该位于该函数被调用的位置之前
