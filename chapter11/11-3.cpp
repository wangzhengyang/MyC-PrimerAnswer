#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> simap;
    string word;
    while(cin >> word){
        simap[word]++;
    }
    for(auto &i : simap){
        cout << i.first << " occurs " << i.second << endl;
    }
    return 0;
}

