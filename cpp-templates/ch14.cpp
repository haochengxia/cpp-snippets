// 模板的多态威力
// Created by Percy on 2022/6/7.
//

// 多态是一种能令单一的泛型标记关联不同特定行为的能力
// 在C++主要通过继承和虚函数来实现 - 动多态
// 而借助于模板的多态被称为静多态

// 动多态 意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

// -- Example from https://www.runoob.com/cplusplus/cpp-polymorphism.html
#include <iostream>
using namespace std;

class Shape {
protected:
    int width, height;
public:
    Shape( int a=0, int b=0)
    {
        width = a;
        height = b;
    }
    int area()
    {
        cout << "Parent class area :" <<endl;
        return 0;
    }
};
class Rectangle: public Shape{
public:
    Rectangle( int a=0, int b=0):Shape(a, b) { }
    int area ()
    {
        cout << "Rectangle class area :" <<endl;
        return (width * height);
    }
};
class Triangle: public Shape{
public:
    Triangle( int a=0, int b=0):Shape(a, b) { }
    int area ()
    {
        cout << "Triangle class area :" <<endl;
        return (width * height / 2);
    }
};
// 程序的主函数
int main( )
{
    Shape *shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    return 0;
}
// --

// 而对于静多态，不再依赖于派生
template <typename Obj>
void myArea(Obj const& obj)
{
    obj.area(); // 调用对象类型相应的area计算面积
}

// 静多态涉及到了泛型程序设计的概念，实践STL