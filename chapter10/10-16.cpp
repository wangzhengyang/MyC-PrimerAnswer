#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    sort(words.begin(), words.end());
    auto iter = unique(words.begin(), words.end());
    words.erase(iter, words.end());

    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2){return s1.size() < s2.size();});
    iter = find_if(words.begin(), words.end(), [sz](const string &s){return s.size() > sz;});
    for_each(iter, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

int main()
{
    vector<string> svec{"hello", "wangzhengyang", "hell", "holyshit", "bingo"};
    biggies(svec, 4);
    return 0;
}