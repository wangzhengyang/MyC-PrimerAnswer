#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool islonger(const string &s)
{
    return (s.size() >= 5);
}

int main()
{
    vector<string> svec;
    string word;
    while(cin >> word){
        svec.push_back(word);
    }
    auto mid = partition(svec.begin(), svec.end(), islonger);
    cout << "more than 5:";
    for(auto iter = svec.begin(); iter != mid; ++iter){
        cout << *iter << " ";
    } 
    cout << endl;
    cout << "less than 5:";
    for(auto iter = mid; iter != svec.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}