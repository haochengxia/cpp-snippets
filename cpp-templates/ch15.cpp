// trait与policy类
// Created by Percy on 2022/6/7.
//

#include "iostream"

// 计算某一序列值的总和

// trait

template <typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
public:
    typedef int AccT;
//    static AccT const zero = 0;
    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<short> {
public:
    typedef int AccT;
//    static AccT const zero = 0;

    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<int> {
public:
    typedef long AccT;
//    static AccT const zero = 0;

    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<unsigned int> {
public:
    typedef unsigned long AccT;
//    static AccT const zero = 0;

    static AccT zero() {
        return 0;
    }
};

template<>
class AccumulationTraits<float> {
public:
    typedef double AccT;
//    static AccT const zero = 0.0; // Error 需要整型或枚举类型

    static AccT zero() {
        return 0.0;
    }
};

template <typename T>
inline typename AccumulationTraits<T>::AccT accum (T const* beg, T const* end)
{
    // 返回值类型是一个元素类型的trait
    typedef typename AccumulationTraits<T>::AccT AccT;

    AccT total = AccumulationTraits<T>::zero();
    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

int main()
{
    int num[] = {1, 2, 3, 4, 5};
    char name[] = "templates";
    int name_len = sizeof(name) - 1;

    std::cout << accum(&num[0], &num[5]) / 5 << std::endl;
    std::cout << accum(&name[0], &name[name_len]) / name_len << std::endl;

    return 0;
}

// 上面的trait示例使得主类型和额外类型、常数等信息相关联
// trait 提供了一种配置具体元素的途径，上例为fixed trait

// 参数化trait, 添加缺省模板实参
//template <typename T, typename AT = AccumulationTraits<T> >
//class Accum {
//public:
//    static typename  AT::AccT accum (T const* beg, T const* end)
//    {
//        typename AT:AccT total = AT::zero();
//        ...
//    }
//};

// Policy
// 累积可能不是求和，也可能是求积等操作，那么如何让 total += *beg 可变

class MultiPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate (T1& total, T2 const& total)
    {
        total *= value;
    }
};

class SumPolicy {
public:
    template<typename T1, typename T2>
    static void accumulate (T1& total, T2 const& total)
    {
        total += value;
    }
};

// 然后可以将类作为缺省模板实参传入，调用，改变时指定模板参数即可
// policy更关注行为，trait更关注类型