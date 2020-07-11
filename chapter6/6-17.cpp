#include <iostream>
#include <string>

using namespace std;

bool StringHasUpper(const string &s)
{
    for(auto &c : s){
        if(isupper(c)){
            return true;
        }
    }
    return false;
}

string &UpperrToLower(string &s)
{
    for(auto &c : s){
        c = tolower(c);
    }
    return s;
}

int main()
{
    string s("hello wOrld!");
    cout << s << " has upper?:" << boolalpha << StringHasUpper(s) << endl;
    cout << "Change to lower:" << UpperrToLower(s) << endl;
    return 0;
}