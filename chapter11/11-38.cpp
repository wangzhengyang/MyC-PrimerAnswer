#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    /* 单词计数程序
    unordered_map<string, int> wordmaps;
    string s;
    while(cin >> s){
        wordmaps[s]++;
    }
    for(auto &s : wordmaps){
        cout << s.first << " " << s.second << endl;
    }
    */

    unordered_map<string, string> wordmaps = {
        {"k", "okay?"},
        {"y", "why"},
        {"r", "are"},
        {"u", "you"},
        {"pic", "picture"},
        {"thk", "thanks!"},
        {"18r", "later"},
    };
    string s;
    while(cin >> s){
        auto iter = wordmaps.find(s);
        if(iter == wordmaps.end()){
            cout << s << " ";
        }else{
            cout << wordmaps[s] << " ";
        }
    }
    cout << endl;
    return 0;
}