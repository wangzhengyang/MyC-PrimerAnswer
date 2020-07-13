#include <iostream>

using namespace std;

void f()
{
    cout << "no parameter!" << endl;
}

void f(int val)
{
    cout << "one parameter:" << val << endl;
}

void f(int val1, int val2)
{
    cout << "two parameter:" << val1 << " " << val2 << endl;
}

void f(double val1, double val2)
{
    cout << "two parameter:" << val1 << " " << val2 << endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}