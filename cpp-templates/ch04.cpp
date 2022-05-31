// 非类型模板参数
// Created by Percy on 2022/5/31.
//

#include "stdexcept"

#include "iostream"
#include "string"
#include "cstdlib"

template <typename T, int MAXSIZE>
class Stack {
private:
    T elems[MAXSIZE];
    int numElems;
public:
    Stack();
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
        return numElems == 0;
    }
    bool full() const {
        return numElems == MAXSIZE;
    }
};

template <typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack() : numElems(0) {}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const& elem)
{
    if (numElems == MAXSIZE) {
        throw std::out_of_range("Stack<>::push() : stack is full");
    }
    elems[numElems] = elem;
    ++numElems;
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
    if (numElems <= 0) {
        throw std::out_of_range("Stack<>::pop() : empty stack");
    }
    --numElems;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
    if (numElems <= 0) {
        throw std::out_of_range("Stack<>::top() : empty stack");
    }
    return elems[numElems-1];
}

// 非类型函数模板参数
template <typename T, int VAL>
T addValue(T const& x)
{
    return x + VAL;
}

//std::transform (source.begin(), source.end(), dest.begin(), (int(*)(int const&)) addValue<int, 5>);

int main()
{
    std::cout << addValue<int, 5>(1) << std::endl;
    try {
        Stack<int, 20> int20Stack;
        Stack<int, 40> int40Stack;
        Stack<std::string, 40> stringStack;

        int20Stack.push(7);
        std::cout << int20Stack.top() << std::endl;
        int20Stack.pop();

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

// 非类型模板参数有限制，通常是常整数或是指向外部链接对象的指针，浮点数和类对象不行
// template<double VAT> ❌
// template<std::string name> ❌

