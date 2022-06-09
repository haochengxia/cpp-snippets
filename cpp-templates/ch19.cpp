// 类型区分
// Created by Percy on 2022/6/9.
//

#include "iostream"

template <typename T>
class IsFundaT {
public:
    enum { Yes = 0, No = 1};
};

// 用于特化基本类型的宏
#define MK_FUNDA_TYPE(T) template<> class IsFundaT<T> {public: enum { Yes = 1, No = 0 };};

MK_FUNDA_TYPE(void)

MK_FUNDA_TYPE(bool)
MK_FUNDA_TYPE(char)
MK_FUNDA_TYPE(signed char)
MK_FUNDA_TYPE(unsigned char)
MK_FUNDA_TYPE(wchar_t)

MK_FUNDA_TYPE(signed short)
MK_FUNDA_TYPE(unsigned short)
MK_FUNDA_TYPE(signed int)
MK_FUNDA_TYPE(unsigned int)
MK_FUNDA_TYPE(signed long)
MK_FUNDA_TYPE(unsigned long)

#if LONGLONG_EXISTS
MK_FUNDA_TYPE(signed long long)
MK_FUNDA_TYPE(unsigned long long)
#endif

MK_FUNDA_TYPE(float)
MK_FUNDA_TYPE(double)
MK_FUNDA_TYPE(long double)

#undef MK_FUNDA_TYPE

template <typename T>
void test (T const& t)
{
    if (IsFundaT<T>::Yes) {
        std::cout << "T is fundamental type" << std::endl;
    } else {
        std::cout << "T is no fundamental type" << std::endl;
    }
}

class MyType{};

int main()
{
    test(7);
    test(MyType());
    return 0;
}