#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    if(42 = i){}//编译器报错
    if(i = 42){}//i完成赋值操作，且if判定条件始终为真
    return 0;
}