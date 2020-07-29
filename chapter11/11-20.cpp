#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
    map<string, int> word_count;
    string s;
    while(cin >> s){
        auto iter = word_count.insert(make_pair(s, 1));
        if(!iter.second){
            iter.first->second++;
        }
        /*word_count[s]++ 版本更好理解*/
    }
    for(auto &i : word_count){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}