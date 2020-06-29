#include <iostream>

using namespace std;

int i = 100, sum = 0;

int main()
{
    for(int i = 0; i != 10; ++i){
        sum += i;
    }//for循环结束 局部变量i被销毁 
    //这里使用全局变量i 
    std::cout << i << " " << sum << std::endl;
    return 0;
}