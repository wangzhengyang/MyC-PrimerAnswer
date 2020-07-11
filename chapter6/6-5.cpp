#include <iostream>

using namespace std;

int myabs(int val){
    if(val < 0){
        val = -val;
    }
    return val;
}

int main()
{
    cout << "abs -10 is " << myabs(-10) << endl;
    cout << "abs 10 is " << myabs(10) << endl;
    cout << "abs -1 is " << myabs(-1) << endl;
    return 0;
}