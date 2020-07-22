#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int func(vector<string> &ivec, vector<string>::size_type sz)
{
    return count_if(ivec.begin(), ivec.end(), [=](const string &s){return s.size() > sz;});
}

int main()
{
    vector<string> svec{"hello", "holyshit", "hellboy", "ironman"};
    cout << func(svec, 6) << endl;
    return 0;
}