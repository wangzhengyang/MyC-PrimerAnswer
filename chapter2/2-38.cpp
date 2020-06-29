#include <iostream>

using namespace std;

//decltype 只指定类型，但不指定值
//auto 指定类型，同时指定值

int main()
{
    int a = 3, b = 4;
    auto c = a;
    decltype(a) d = b;

    cout << "c is " << c << endl;
    cout << "d is " << d << endl;
    return 0;
}