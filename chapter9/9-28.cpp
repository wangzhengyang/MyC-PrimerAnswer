#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void flst_find(forward_list<string> &f, string &s1, string &s2)
{
    forward_list<string>::iterator prev;
    for (auto iter = f.begin(); iter != f.end();)
    {
        if (*iter == s1)
        {
            iter = f.insert_after(iter, s2);
            prev = iter;
            return;
        }
        else
        {
            prev = iter;
        }
        ++iter;
    }
    f.insert_after(prev, s2);
    return;
}

int main()
{
    forward_list<string> fslst{"hello", "world", "wangzhengyang"};
    string s1 = "hello";
    string s2 = "shit";
    flst_find(fslst, s1, s1);
    for (auto s : fslst)
    {
        cout << s << " ";
    }
    cout << endl;
    flst_find(fslst, s2, s2);
    for (auto s : fslst)
    {
        cout << s << " ";
    }
    cout << endl;
}