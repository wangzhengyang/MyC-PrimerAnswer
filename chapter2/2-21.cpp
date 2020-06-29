#include <iostream>

using namespace std;

int main()
{
    int i= 0;
    double *dp = &i;    //指针所指向的数据类型不符
    int *ip = i;    //未使用取值运算符
    int *p = &i;    //正确
    return 0;
}