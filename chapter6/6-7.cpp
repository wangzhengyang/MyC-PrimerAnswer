#include <iostream>

using namespace std;

void print()
{
    static int val = 0;
    cout << "val is " << val++ << endl;
}

int main()
{
    print();
    print();
    return 0;
}