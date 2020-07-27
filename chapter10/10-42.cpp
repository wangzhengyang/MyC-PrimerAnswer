#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    list<string> slst{"hello", "world", "wangzhengyang"};
    slst.sort();
    slst.unique();
    for(auto &s : slst){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}