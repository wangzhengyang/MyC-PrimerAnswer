#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    string s;
    list<string> lst;
    while(cin >> s){
        lst.push_back(s);
    }
    for(auto &s : lst){
        cout << s << endl;
    }
    return 0;
}