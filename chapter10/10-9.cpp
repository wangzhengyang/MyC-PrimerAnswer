#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;
    string s;
    while(cin >> s){
        svec.push_back(s);
    }
    cout << "before:";
    for(auto &s : svec){
        cout << s << " ";
    }
    cout << endl;
    sort(svec.begin(), svec.end());
    auto iter = unique(svec.begin(), svec.end());
    svec.erase(iter, svec.end());
    cout << "after:";
    for(auto &s : svec){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}