#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isShorter(const string& s1, const string &s2)
{
    return (s1.size() < s2.size());
}

int main()
{
    vector<string> svec;
    string word;
    while(cin >> word){
        svec.push_back(word);
    }
    sort(svec.begin(), svec.end());
    auto iter = unique(svec.begin(), svec.end());
    svec.erase(iter, svec.end());

    stable_sort(svec.begin(), svec.end(), isShorter);
    for(auto &s : svec){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}