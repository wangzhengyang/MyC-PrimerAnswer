#include <iostream>

using namespace std;

int main()
{
    int i; double d;
    d = i = 3.5;
    cout << d << " " << i << endl; //d = 3.0 i = 3
    i = d = 3.5;
    cout << d << " " << i << endl; //d = 3.5 i = 3
    return 0;
}