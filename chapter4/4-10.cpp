#include <iostream>

using namespace std;

int main()
{
    int temp;
    while(cin >> temp){
        if(temp == 42) break;
        cout << temp << endl;
    }
    cout << "get " << temp << endl;
    return 0;
}