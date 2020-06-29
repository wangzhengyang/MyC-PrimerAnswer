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

    cout << "a before is " << a;
    a = 42; //可以
    cout << "after is " << a << endl;
    cout << "b before is " << b; 
    b = 42; //可以
    cout << "after is " << b << endl;
    cout << "c before is " << c;
    c = 42; //可以
    cout << "after is " << c << endl;

    return 0;
}