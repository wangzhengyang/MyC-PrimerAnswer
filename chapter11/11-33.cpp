#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> wordmap = {
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
        auto iter = wordmap.find(s);
        if(iter == wordmap.end()){
            cout << s << " ";
        }else{
            cout << wordmap[s] << " ";
        }
    }
    cout << endl;
    return 0;
}