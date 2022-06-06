// 实例化
// Created by Percy on 2022/6/5.
//

// On-demand 实例化
template<typename T> class C;

C<int>* p = 0;

template<typename T>
class C {
public:
    void f();
};

void g (C<int>& c)
{
    c.f();
}

// 延迟实例化
// 模板的实例化程度，只对确实需要的部分进行实例化
template <typename T>
class Safe {};

template <int N>
class Danger {
public:
    typedef char Block[N];
};

template <typename T, int N>
class Tricky {
public:
    virtual ~Tricky() {}
    void no_body_here(Safe<T> = 3);
    void inclass() {
        Danger<N> no_boom_yet;
    }
//    void error() {Danger<0> boom;}
//    void unsafe(T (*p)[N]);
    T operator->();
//    virtual Safe<T> suspect();
    struct Nested {
        Danger<N> pfew;
    };
    union {
        int align;
        Safe<T> anonymous;
    };
};

int main()
{
    Tricky<int, 0> ok;
}
