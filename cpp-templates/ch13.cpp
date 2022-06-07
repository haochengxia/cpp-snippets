// 未来的方向
// Created by Percy on 2022/6/7.
//

#include "list"
#include "vector"

typedef std::vector<std::list<int> > LineTable;

typedef std::vector<std::list<int>> OtherTable; // 有时会有>> 右移的歧义，经测试编译器正常 gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)

int main()
{
    return 0;
}

