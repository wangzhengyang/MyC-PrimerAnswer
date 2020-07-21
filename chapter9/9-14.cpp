#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char *p1 = "hello";
    char *p2 = "world";
    char *p3 = "wangzhengyang";
    list<char *> list{p1, p2, p3};
    vector<string> svec(list.begin(), list.end());
    for(auto &s : svec){
        cout << s << endl;
    }
    return 0;
}