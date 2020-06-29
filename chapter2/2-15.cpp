#include <iostream>

using namespace std;

int main()
{
    int ival = 1.01; 
    int &rval1 = 1.01; //引用初始化绑定的是变量，不能是常量
    int &rval2 = ival; //可以
    int &rval3; //引用初始化必须绑定变量
    return 0;
}