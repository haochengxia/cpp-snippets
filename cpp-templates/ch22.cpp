// 函数对象和回调
// Created by Percy on 2022/6/9.
//

// 函数对象也称仿函数，可以输用函数调用语法进行调用的任何对象

int f1(int const& r)
{
    return ++(int&)r; // 不合理但是合法，引用的值变了
}

int f2(int const& r)
{
    return r;
}

int f3()
{
    return 42;
}

int foo()
{
    int param = 0;
    int answer = 0;
    answer = f1(param);
    f2(param);
    f3();
    return answer + param;
} // 编译器会假设f1 f2 f3都能改变param的值，因此这些调用会使得编译器优化很困难

// 而内联调用优化就会好很多

// 重载操作符 () 来让class等作为仿函数

