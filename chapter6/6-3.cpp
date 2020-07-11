#include <iostream>

using namespace std;

int fact(int val)
{
    int ret = 1;
    int i = 1;
    while(i <= val){
        ret *= i++;
    }
    return ret;
}


int main()
{
    cout << "val is 5, result is " << fact(5) << endl;
    cout << "val is 10, result is " << fact(10) << endl;
    return 0;
}