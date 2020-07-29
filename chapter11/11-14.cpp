#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    map<string, vector<pair<string, string>>> children;
    children["wang"].push_back(make_pair("zhengyang", "1991-11-5"));
    children["wang"].push_back(make_pair("zheng", "1990-10-1"));
    for(auto &cd : children){
        for(auto &i : cd.second){
            cout << cd.first << " " << i.first << " " << i.second << endl;
        }
    }
    return 0;
}