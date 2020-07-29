#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    multimap<string, string> namemap;
    namemap.insert({"wang", "zhengyang"});
    namemap.insert({"liu", "qin"});
    namemap.insert({"wang", "zheng"});
    for(auto &i : namemap){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}