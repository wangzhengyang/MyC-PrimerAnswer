#include <iostream>

using namespace std;

void myswap(int **p1, int **p2)
{
    *p1 = (int *)((long)*p1 ^ (long)*p2);
    *p2 = (int *)((long)*p1 ^ (long)*p2);
    *p1 = (int *)((long)*p1 ^ (long)*p2);
}

int main()
{
    int val1 = 5, val2 = 10;
    int *p1 = &val1, *p2 = &val2;
    cout << "p1 is " << p1 << " p2 is " << p2 << endl;
    cout << "*p1 is " << *p1 << " *p2 is " << *p2 << endl;
    myswap(&p1, &p2);
    cout << "p1 is " << p1 << " p2 is " << p2 << endl;
    cout << "*p1 is " << *p1 << " *p2 is " << *p2 << endl;
}