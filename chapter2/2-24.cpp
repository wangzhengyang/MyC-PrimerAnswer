#include <iostream>

using namespace std;

int main()
{
    int i = 42;
    void *p = &i; //可以 void* 仅仅记录对象的地址
    long *lp = &i; //不可以 指针所指向的数据类型与真实数据类型不符
    return 0;
}