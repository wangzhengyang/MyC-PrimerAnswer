#include <iostream>

using namespace std;

//使用引用更易于使用
void myswap(int &val1, int &val2)
{
    val1 = val1^val2;
    val2 = val1^val2;
    val1 = val1^val2;
}

int main()
{
    int val1 = 10, val2 = 5;
    cout << "val1 is " << val1 << " val2 is " << val2 << endl;
    myswap(val1, val2);
    cout << "val1 is " << val1 << " val2 is " << val2 << endl;
    return 0;
}
