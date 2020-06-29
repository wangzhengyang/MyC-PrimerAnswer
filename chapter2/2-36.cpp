#include <iostream>

using namespace std;

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;      //c是变量
    decltype((b)) d = a;    //d是a的引用
    ++c;
    ++d;
    //结果a = 4, b = 4, c = 4, d = 4
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
    cout << "d is " << d << endl;
    return 0;
}