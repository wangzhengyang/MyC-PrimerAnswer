#include <iostream>

using namespace std;

int main()
{
    int i = -1, &r = 0; //引用只能初始化变量
    int i2 = 0;
    int *const p2 = &i2; //可以
    const int i = -1, &r = 0; //可以
    const int *const p3 = &i2; //可以
    const int *p1 = &i2; //可以
    const int &const r2; //不可以，必须初始化一个常量值给r2
    const int &const r3 = 0x10; //修改，可以通过
    const int i2 = i, &r = i; //可以，引用那边会通过拷贝生成常量值
    return 0;
}