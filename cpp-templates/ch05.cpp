// 技巧性基础知识
// Created by Percy on 2022/5/31.
//

#include "iostream"
#include "bitset"
#include "string"
#include "deque"
#include "vector"

template <typename T>
void printColl (T const& coll)
{
    typename T::const_iterator pos; // 访问依赖于模板参数的类型名称
    typename T::const_iterator end(coll.end());

    for (pos=coll.begin(); pos!=end; ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

// 前面存在依赖于模板参数的对象时，需要在模板内部使用.template 标记
template <int N>
void printBitSet (std::bitset<N> const& bs)
{
    std::cout << bs.template to_string<char, std::char_traits<char>, std::allocator<char> >();
}

// 对于那些在基类中声明，并且依赖于模板参数的符号，this->或者Base<T>::
template <typename T>
class Base {
public:
    void exit();
};

template <typename T>
void Base<T>::exit() {
    std::cout << "invoke Base<T>::exit()" << std::endl;
}

template <typename T>
class Derived : Base<T> {
public:
//    void foo() {
//        exit(); // 会调用外部的exit，不会考虑基类Base中定义的exit()
//    }
    void foo2() {
//        Base<T>::exit();
        this->exit();
    }
};

template <typename T>
class Stack {
private:
    std::deque<T> elems;

public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }

    template<typename T2>
    Stack<T>& operator= (Stack<T2> const&);
};

template <typename T>
void Stack<T>::push(T const& elem) // 使用完整类型限定符 Stack<T>
{
    elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop() : empty stack");
    }
    elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop() : empty stack");
    }
    return elems.back();
}

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2) {
    std::cout << "invoke template = op" << std::endl;
    if ((void*)this == (void*)&op2) {
        return *this;
    }

    Stack<T2> tmp(op2);

    elems.clear();
    while (!tmp.empty()) {
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}

//int main() {
//    Derived<int> d;
//    // d.foo();
//    d.foo2();
//
//    Stack<int> intStack;
//    Stack<float> floatStack;
//    intStack.push(1);
//    floatStack.push(1.1);
//    floatStack = intStack;
//    std::cout << floatStack.top() << std::endl;
//
//    Stack<int> intStack2;
//    intStack2.push(10);
//    intStack2 = intStack; // 同类型，没有调用模板复制运算符，而是调用缺省赋值运算符
//}

// 模板的模板参数
//template <typename T, typename CONT=std::deque<T> >
//class Stack
//{
//private:
//    CONT elems;
//};
//
//Stack<int, std::vector<int>> vStack; // 为了指定内部容器的类型，需要同时传递容器和内部元素类型
//Stack<int, std::vector> vStack; // 如何做到像这样指定
//
//template <typename T, template<typename ELEM, typename ALLOC = std::allocator<ELEM>> class CONT = std::deque >
//class Stack {
//private:
//    CONT<T> elems;
//};

// 零初始化
template <typename T>
void foo()
{
    T x = T(); // int double 指针等基本类型需要显式调用确认构造函数来初始化值，内建类型也是
}

template <typename T>
class MyClass {
private:
    T x;
public:
    MyClass() : x() {}
    T val() const {
        return x;
    }
};

int main()
{
    int x;
    std::cout << x << std::endl;
    MyClass<int> m;
//    MyClass<int> m = MyClass<int>();
    std::cout << m.val() << std::endl;
};

//template <typename T>
//inline T const& max (T const& a, T const& b)
//{
//    ...
//}
//
//::max("apple", "peach"); // OK
//::max("apple", "tomato"); // ERROR, char const[6] & char const[7]
//
//template <typename T>
//inline T const& max (T const a, T const b)
//{
//    ...
//}
//
//::max("apple", "peach"); // OK
//::max("apple", "tomato"); // OK, char const* & char const*
