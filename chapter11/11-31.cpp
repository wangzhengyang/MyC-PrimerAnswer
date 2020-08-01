#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> authors = {
        {"wang", "bigword",},
        {"shit", "shitword"},
        {"wang", "fuck"},
    };
    for(auto &i : authors){
        cout << i.first << " " << i.second << endl;
    }
    string s;
    cin >> s;
    auto iters = authors.equal_range(s);
    auto iter = iters.first;
    for(; iter != iters.second;){
        iter = authors.erase(iter);
    }
    for(auto &i : authors){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}