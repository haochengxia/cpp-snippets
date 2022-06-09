// 表达式模板
// Created by Percy on 2022/6/9.
//

// 为了支持一种数值数组的类而引入 expression template

// 表达式模板适用于能够在运行期确定大小、中等大小的数组

// 在常规编程中，为了避免临时对象创建的开销，常用包含计算的赋值运算符来代替纯粹的赋值运算符

// 在模板实参中编码表达式，例如计算 1.2 * x + x * y 可以转化成 A_Add< A_Multi < A_Scalar<double>, Array<double> >, A_Multi < Array<double>, Array<double> > >

#include "stddef.h"
#include "cassert"

template <typename T> class A_Scalar;

// primary template
template <typename T>
class A_Traits {
public:
    typedef T const& ExprRef;     // type to refer to is constant reference
};

template <typename T>
class A_Scalar {
private:
    T const& s;
public:
    A_Scalar(T const& v) : s(v) {}
    T operator[] (size_t) const {
        return s;
    }
    size_t size() const {
        return 0;
    }
};

// partial specialization for scalars
template <typename T>
class A_Traits<A_Scalar<T> > {
public:
    typedef A_Scalar<T> ExprRef;  // type to refer to is ordinary value
};

template<typename T, typename OP1, typename OP2>
class A_Add {
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;
public:
    A_Add (OP1 const& a, OP2 const& b) : op1(a), op2(b) {

    }

    T operator[] (size_t idx) const {
        return op1[idx] + op2[idx];
    }

    size_t size() const {
        assert(op1.size() == 0 || op2.size()==0 || op1.size() == op2.size());
        return op1.size()!=0? op1.size() : op2.size();
    }
};

template <typename T, typename OP1, typename OP2>
class A_Multi {
private:
    typename A_Traits<OP1>::ExprRef op1;
    typename A_Traits<OP2>::ExprRef op2;

public:
    A_Multi (OP1 const& a, OP2 const& b) : op1(a), op2(b) {

    }

    T operator[] (size_t idx) const {
        return op1[idx] * op2[idx];
    }

    size_t size() const {
        assert(op1.size() == 0 || op2.size()==0 || op1.size() == op2.size());
        return op1.size()!=0? op1.size() : op2.size();
    }
};

int main()
{
    return 0;
}