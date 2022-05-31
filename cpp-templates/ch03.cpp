// 类模板
// Created by Percy on 2022/5/30.
//

#include <vector>
#include "stdexcept"

#include "iostream"
#include "string"
#include "cstdlib"

#include "deque"

template <typename T>
class Stack {
private:
    std::vector<T> elems;

public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }

//    Stack (Stack<T> const &); // 拷贝构造函数 类的类型为Stack<T>
//    Stack<T>& operator= (Stack<T> const&);
};

// 类模板的成员函数为函数模板
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

typedef Stack<int> IntStack; // 模板实参可以是任何类型，唯一要求是该类型必须提供被调用的所有操作

// 特化模板，类似与函数模板重载，优化特定类型的实现
template<>
class Stack<std::string>
{
private:
    std::deque<std::string> elems;

public:
    void push(std::string const&);
    void pop();
    std::string top() const;
    bool empty() const {
        return elems.empty();
    }
};

void Stack<std::string>::push(std::string const& elem)
{
    elems.push_back(elem);
}

void Stack<std::string>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::pop() : empty stack");
    }
    elems.pop_back();
}

std::string Stack<std::string>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<std::string>::top() : empty stack");
    }
    return elems.back();
}

// 局部特化, 存在相同程度匹配二义性的可能
//template <typename T1, typename T2>
//class MyClass {};
//
//template <typename T>
//class MyClass<T, int> {};

// 缺省模板实参
//template <typename T, typename CONT = std::vector<T> >

int main()
{
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout << intStack.top() << std::endl;

        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (std::exception const& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
