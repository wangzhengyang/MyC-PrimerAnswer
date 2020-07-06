#include <iostream>

using namespace std;

//'q'二进制 01110001 'q'<<6 得到 01110001000000 ~'q'<<6 得到 111111111111111111 10001110111111

int main()
{
    cout << hex << ~'q'<<6 << endl;
    return 0;
}