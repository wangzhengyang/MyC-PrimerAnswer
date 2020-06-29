#include <iostream>
#include <string>

using namespace std;

/*
* string是标准库类型，在定义变量时，都会通过构造函数完成变量的初始化过程
* int 是内置系统类型，全局变量的int类型在编译时分配完成在data段，在程序运行开始前已经完成初始化为0
* 局部变量的int类型分配在栈中，由于未初始化，所有该位置的数据是脏数据
*/
/*局部变量定义时最好同时完成初始化*/

std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;

    cout << "global_str is " << global_str << endl;
    cout << "global_int is " << global_int << endl;
    cout << "local_int is " << local_int << endl;
    cout << "local_str is " << local_str << endl;
    return 0;
}