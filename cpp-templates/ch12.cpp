// 特化与重载
// Created by Percy on 2022/6/6.
//

#include "iostream"

template<typename T>
class Array {
private:
    T* data;
public:
    Array(Array<T> const&);
    Array<T>& operator= (Array<T> const&);

    void exchange_with(Array<T>* b)
    {
        T *tmp = data;
        data = b->data;
        b->data = tmp;
    }

    T& operator[] (size_t k)
    {
        return data[k];
    }
};

// 泛型代码
template <typename T> inline
void exchange (T* a, T* b)
{
    T tmp(*a);
    *a = *b;
    *b = tmp;
}

// 透明自定义
template <typename T> inline
void quick_exchange(T* a, T* b)
{
    T tmp(*a);
    *a = *b;
    *b = tmp;
}

template <typename T> inline
void quick_exchange(Array<T> *a, Array<T> *b)
{
    a->exchange_with(b);
}

void demo(Array<int>* p1, Array<int>* p2)
{
    int x, y;
    quick_exchange(&x, &y); // use (1)
    quick_exchange(p1, p2); // use (2) 两个函数模板都可以匹配，但是认为2比1更加特殊，重载解析规则会优先选择更加特殊的模板
}

template <typename T>
int f(T)
{
    return 1;
}

template <typename T>
int f(T*)
{
    return 2;
}

void func_overload()
{
    std::cout << f<int*>((int*)0) << std::endl; // 不仅仅同名模板可以同时存在，其实例化体也可以，即使这些实例化体具有相同的参数类型和返回类型
    std::cout << f<int>((int*)0) << std::endl;
}

int main()
{
    func_overload();
    return 0;
}

// 重载函数模板的正式排序原则
// 假设有两个函数模板ft1和ft2,若ft1针对ft2构造的实参列表能够演绎而反之不行，则称ft2更加特殊