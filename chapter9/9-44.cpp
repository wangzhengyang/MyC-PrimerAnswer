#include <iostream>
#include <string>

using namespace std;

void fuc(string &s, string &oldVal, string &newVal)
{
    int p = 0;
    while((p = s.find(oldVal, p)) != string::npos){
        s.replace(p, oldVal.size(), newVal);
        p += newVal.size();
    }
}

int main()
{
    string s("hell world, hell wangzhengyang, hell");
    string oldVal("hell");
    string newVal("hello");
    fuc(s, oldVal, newVal);
    cout << s << endl;
    return 0;
}