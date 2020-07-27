#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> simap;
    string s;
    string dot(".,");
    while (cin >> s)
    {
        int pos = 0;
        //也可以在一个循环中完成操作
        while((pos = s.find_first_of(dot, pos)) != -1){
            s.erase(pos, 1);
        }
        for(auto &i : s){
            i = tolower(i);
        }
        simap[s]++;
    }
    for(auto &i : simap){
        cout << i.first << " occurs " << i.second << ((i.second > 1)? "times":"time") << endl;
    }
    return 0;
}