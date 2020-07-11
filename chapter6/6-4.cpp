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
    cout << "Enter a number:";
    int val;
    if(cin >> val){
        cout << "the val is " << val << ",result is " << fact(val) << endl;
    }else{
        cout << "format error!";
    }
    return 0;
}