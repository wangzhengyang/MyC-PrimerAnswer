#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int t1, t2;
    cin >> t1 >> t2;
    if(t2 == 0){
        throw runtime_error("t2 is zero!");
    }else{
        cout << t1 / t2 << endl;
    }
    return 0;
}