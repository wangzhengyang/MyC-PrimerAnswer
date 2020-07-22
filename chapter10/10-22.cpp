#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isShorter(const string &s)
{
    return (s.size() < 6);
}

int main()
{
    vector<string> svec{"hello", "holyshit", "abc", "wang", "hellboy"};
    auto mid = partition(svec.begin(), svec.end(), isShorter);
    for(auto iter = svec.begin(); iter != mid; ++iter){
        cout << *iter << endl;
    }
    return 0;
}