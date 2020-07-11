#include <iostream>

using namespace std;

void myreset(int &val)
{
    val = 0;
}

int main()
{
    int val = 10;
    cout << "val is " << val << endl;
    myreset(val);
    cout << "val is " << val << endl;
}