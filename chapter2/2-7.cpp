#include <iostream>

using namespace std;

/*
* \145 表示 'e' \012 表示 '\n'
* 3.14e1l 表示 long double
* 1024f 编译器不通过 改为 1024.f通过 表示 float
* 3.14L 表示 long double
*/


int main()
{
    cout << "Who goes with F\145rgus?\012" << endl;
    cout << "3.14e1L size is " << sizeof(3.14e1L) << endl;
    cout << "1024.f size is " << sizeof(1024.f) << endl;
    cout << "3.14L size is "  << sizeof(3.14L) << endl;
    return 0;
}