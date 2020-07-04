#include <iostream>

using namespace std;
//由于字符串没有空字符，所以输出的时候可以会输出除字符串以外其他的值，出现打印溢出的问题
int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while(*cp){
        cout << *cp << endl;
        ++cp;
    }
    return 0;
}