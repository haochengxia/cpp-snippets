// tuple
// Created by Percy on 2022/6/9.
//

// 包含异类对象

//// duo 和 std::pair 相似
//template <typename T1, typename T2>
//struct Duo {
//    T1 v1;
//    T2 v2;
//};

template <typename T1, typename T2>
class Duo {
public:
    T1 v1; // 第一个域的值
    T2 v2; // 第二个域的值

    Duo() : v1(), v2() {}
    Duo(T1 const& a, T2 const& b) : v1(a), v2(b) {}
};

// 辅助函数，演绎duo中域的类型
template <typename T1, typename T2>
inline Duo<T1, T2> make_duo (T1 const& a, T2 const& b)
{
    return Duo<T1, T2>(a, b);
}

// 进一步优化提供对域类型的访问，即为加入 typedef T1 Type1 和 typedef T2 Type2

// 可递归duo
//template <typename A, typename B, typename C>
//class Duo<A, Duo<B, C> > {
//public:
//    typedef A T1;
//    typedef Duo<B, C> T2;
//    enum {N = Duo<B, C>::N + 1};
//
//private:
//    T1 value1;
//    T2 value2;
//
//public:
//    ...
//};

// 特化
// template<typename A>
// struct Duo<A, void> {
// public:
//    typedef A T1;
//    typedef void T2;
//    enum {N=1};
//...
//};

// tuple 派生自 Duo，确定域的个数后，展开为可递归duo

// Tuple<bool, int, float, NullT> ->
// Duo<bool, Tuple<int, float, NullT, NullT>:BaseT> ->
// Duo<int, float>
