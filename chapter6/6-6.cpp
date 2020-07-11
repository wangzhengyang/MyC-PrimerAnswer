#include <iostream>

using namespace std;

/*
* 行参：在函数调用时初始化，将实参传递给行参，退出函数时销毁行参
* 局部变量：在函数内部初始化，在出函数时销毁局部变量
* 局部静态变量：在函数内部第一次进入时，完成变量的初始化过程，在以后函数调用，不会在初始化该函数
* 局部静态变量只能在函数内部使用
*/

void print(int  val){
    int temp = 5;
    static int stemp = 0;
    cout << "val is " << val << endl;
    cout << "temp is " << temp << endl;
    cout << "stemp is " << stemp++ << endl;

}

int main()
{
    print(5);
    print(10);
    return 0;
}