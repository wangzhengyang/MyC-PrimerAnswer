#include <iostream>
#include <string>
#include <vector>

using namespace std;

string &change(string &s, string &preffix, string &subffix)
{
    s.insert(s.begin(), preffix.begin(), preffix.end());
    s.append(subffix.begin(), subffix.end());
    return s;
}

int main()
{
    string s("wangzhengyang");
    string prefix("Mr.");
    string subfix("II");
    cout << change(s, prefix, subfix) << endl;
    return 0;
}