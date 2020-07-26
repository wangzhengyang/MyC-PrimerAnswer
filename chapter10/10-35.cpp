#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec{"hello", "world", "wangzhengyang"};
    auto iter = svec.end();
    for(--iter; iter != svec.begin(); --iter){
        cout << *iter << " ";
    }
    cout << *iter << " ";
    cout << endl;
    return 0;
}