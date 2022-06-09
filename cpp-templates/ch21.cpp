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