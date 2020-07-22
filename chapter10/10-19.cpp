#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void biggies(vector<string> words, vector<string>::size_type sz)
{
    sort(words.begin(), words.end());
    auto iter = unique(words.begin(), words.end());
    words.erase(iter, words.end());
    iter = stable_partition(words.begin(), words.end(), [sz](const string &s){return s.size() < sz;});
    for_each(iter, words.end(), [](const string &s){cout << s << endl;});
}

int main()
{
    vector<string> svec{"hello", "shit", "holyshit", "wangzhengyang", "mayday", "mayaay"};
    biggies(svec, 6);
    return 0;
}