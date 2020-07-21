#include <iostream>
#include <string>

using namespace std;

string &func(string &s, string &pref, string &subf)
{
    s.insert(0, pref);
    s.insert(s.size(), subf);
    return s;
}

int main()
{
    string s("wangzhengyang");
    string pref("Mr.");
    string subf("II");
    cout << func(s, pref, subf) << endl;
    return 0;
}