#include <iostream>

using namespace std;

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159; //可以
    cout << "i " << i << " d " << d << endl;
    r2 = r1; //可以
    cout << "i " << i << " d " << d << endl;
    i = r2;
    cout << "i " << i << " d " << d << endl;
    r1 = d;
    cout << "i " << i << " d " << d << endl;
    return 0;
}