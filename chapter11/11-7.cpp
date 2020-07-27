#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string> > family;
    family["wang"].push_back("zhengyang");
    family["wang"].push_back("hello");
    family["wang"].push_back("shit");
    for(auto &i : family){
        for(auto &j : i.second){
            cout << "first name:" << i.first << "last name:" << j << endl;
        }
    }
    return 0;
}