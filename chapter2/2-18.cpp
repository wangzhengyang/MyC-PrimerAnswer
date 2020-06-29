#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    int *pi = nullptr;
    cout << "pi is " << pi << endl;
    pi = &i;//更改pi值
    cout << "pi is " <<  pi << endl;
    *pi = 15; //更改指针所指对象的值
    cout << "i is " << i << endl;
    return 0;
}