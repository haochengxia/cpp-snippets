// 类模板
// Created by Percy on 2022/5/30.
//

#include <vector>
#include "stdexcept"

#include "iostream"
#include "string"
#include "cstdlib"

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
