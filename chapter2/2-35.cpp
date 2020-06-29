#include <iostream>

using namespace std;

int main()
{
    const int i = 42;

    auto j = i; // j 是int整型
    const auto &k = i;  //k 是常量引用
    auto *p = &i;   //p 是指向整型常量的指针
    const auto j2 = i, &k2 = i; //j2是常量整型, k2是常量整型

    cout << "j before is " << j;
    j = 10;
    cout << " after is " << j << endl;

    // k = 10; //常量引用无法赋值
    cout << "*p before is " << *p;
    //*p = 22;
    //j2 = 10;
    //k2 = 10;
    return 0;
}