#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec{"hello", "world", "wangzhengyang"};
    for(auto iter = svec.crbegin(); iter != svec.crend(); ++ iter){
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}