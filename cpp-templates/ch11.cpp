// 模板实参演绎
// Created by Percy on 2022/6/6.
//

template <typename T>
T const& max(T const& a, T const& b)
{
    return a < b? b : a;
}

//int g = max(1, 1.0); // 每个实参-参数对的分析是独立的，若矛盾则会失败 1 -> int 1.0 -> double

// 实参和参数对是如何进行匹配的
// 匹配类型 A
// 参数化类型 P 例如模板中参数声明为T&，那么P即为T

// 对于引用参数，绑定到该参数的实参是不会进行decay的
template <typename T> void f(T) {}
template <typename T> void g(T&) {}

double x[20];
int const seven = 7;

// 模板实参演绎只能应用于函数模板和成员函数模板，不能应用于类模板
// 类模板的构造函数也不能根据实参来演绎类模板参数

template <typename T>
class S {
public:
    S(T b) : a(b) {}

private:
    T a;
};

int main()
{
    f(x); // decay
    g(x);
    f(seven);
    g(seven);
    f(7);
//    g(7); Error

//    S x(12); Error 不能从构造函数的调用实参12演绎类模板参数T
    S<int> x(12);
    return 0;
}

// 缺省调用实参 不能用于演绎模板实参

// Q: Barton-Nackman 技巧
