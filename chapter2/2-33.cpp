#include <iostream>

using namespace std;

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r;     //a是int整数
    auto b = ci;    //b是int整数 auto会自动忽略顶层const，不忽略底层const
    auto c = cr;    //c是int整数
    auto d = &i;    //d是int*指针
    auto e = &ci;   //d是指向常量整型的指针
    auto &g = ci;   //g是整形常量引用

    a = 42; //可以
    b = 42; //可以
    c = 42; //可以
    d = 42; //不可以
    e = 42; //不可以
    g = 42; //不可以


    return 0;
}