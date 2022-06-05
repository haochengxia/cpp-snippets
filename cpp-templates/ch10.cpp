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
