// meta program
// Created by Percy on 2022/6/8.
//

#include "iostream"

// meta program 含有 对一个程序进行编程的意思，编程系统执行所写代码来生成新的代码

// Pow3<> 为一个template metaprogramming

template <int N>
class Pow3 {
public:
    enum {result = 3*Pow3<N-1>::result};
};

// 用于结束递归的全局特化
template<>
class Pow3<0> {
public:
    enum {result = 1};
};

int main()
{
    std::cout << "Pow3<7>::result = " << Pow3<7>::result << std::endl;
    return 0;
}

// 使用meta program来展开循环
template <int DIM, typename T>
class DotProduct {
public:
    static T result (T* a, T* b) {
        return *a * *b + DotProduct<DIM-1, T>::result(a+1, b+1);
    }
};

template <typename T>
class DotProduct<1, T> {
public:
    static T result (T* a, T* b) {
        return *a * *b;
    }
};

template <int DIM, typename T>
inline T dot_product (T* a, T* b)
{
    return DotProduct<DIM, T>::result(a, b);
}