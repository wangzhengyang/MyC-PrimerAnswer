#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec;
    string s;
    while(getline(cin, s)){
        svec.push_back(s);
    }
    for(auto iter = svec.begin(); iter != svec.end(); ++iter){
        for(auto &c : *iter){
            c = toupper(c);
        }
        cout << *iter << endl;
    }
    return 0;
}