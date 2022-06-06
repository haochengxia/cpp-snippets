// 模板实参演绎
// Created by Percy on 2022/6/6.
//

template <typename T>
T const& max(T const& a, T const& b)
{
    return a < b? b : a;
}

int g = max(1, 1.0); // 每个实参-参数对的分析是独立的，若矛盾则会失败 1 -> int 1.0 -> double

