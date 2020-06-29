#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace::std;

/*
* a. 'a' 单字节 占1字节 L‘a' 宽字节 占4字节 "a" 字符串 占2字节 L"a" 宽字符串 占8字节
* b. 10, 10u, 10L, 10uL 十进制 012 八进制 0xC 十六进制
* c. 3.14 float 3.14f float 3.14L double
* d. 10, 10u 十进制 10. double 10e-2 double
*/

int main()
{
    cout << "L\'a\' size is " << sizeof(L'a') << endl;
    cout << "L\"a\" size is " << sizeof(L"ab") << endl;
    cout << "10 10u 10L 10uL 012 0xC size is " << sizeof(10) << \
    sizeof(10u) << sizeof(10L) << sizeof(10uL) << sizeof(012) << \
    sizeof(0xC) << endl;
    cout << "10e-2 size is " << sizeof(10e-2) << endl;
    cout << "10. size is " << sizeof(10.) << endl;
    return 0;
}