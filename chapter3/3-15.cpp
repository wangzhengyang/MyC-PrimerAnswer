#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    vector<string> svec;
    while(getline(cin, s)){
        svec.push_back(s);
    }
    for(auto &i : svec){
        cout << i << endl;
    }
    return 0;
}