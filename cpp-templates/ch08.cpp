// 深入模板基础
// Created by Percy on 2022/6/1.
//

// C++ 两种基本类型模板：类模板和函数模板

template <typename T>
class List {
public:
    template<typename T2>
    List(List<T2> const&);
};

template <typename T>
template <typename T2>
List<T>::List(List<T2> const& b) {}

// 联合（Union）模板，往往被看作类模板的一种
template <typename T>
union AllocChunk {
    T object;
    unsigned char bytes[sizeof(T)];
};

// 函数模板声明也可以具有缺省调用实参
template <typename T>
void report_top (Stack<T> const&, int number=10);

template <typename T>
void fill(Array<T>*, const& = T()); // 缺省调用实参可以依赖于模板参数， 如果fill被调用的时候总是提供了第二个参数，就不会实例化这个缺省实参，没有这个缺省构造函数也可以
