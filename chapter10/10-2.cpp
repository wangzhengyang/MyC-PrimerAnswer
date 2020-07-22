#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    list<string> slst{"hello", "world", "world", "wangzhengyang", "wangzhengyang", "wangzhengyang"};
    string s;
    cin >> s;
    cout << count(slst.cbegin(), slst.cend(), s) << endl;
    return 0;
}