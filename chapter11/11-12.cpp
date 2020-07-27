#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    vector<pair<string, int>> pvec;
    string s;
    int i;
    while(cin >> s >> i){
        pvec.push_back(make_pair(s, i));
    }
    for(auto &i : pvec){
        cout << i.first << i.second << endl;
    }
    return 0;
}