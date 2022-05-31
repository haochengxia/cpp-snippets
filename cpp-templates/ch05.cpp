// 技巧性基础知识
// Created by Percy on 2022/5/31.
//

#include "iostream"

template <typename T>
void printColl (T const& coll)
{
    typename T::const_iterator pos;
    typename T::const_iterator end(coll.end());

    for (pos=coll.begin(); pos!=end; ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
