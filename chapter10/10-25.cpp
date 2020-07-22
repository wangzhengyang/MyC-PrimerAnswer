#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, vector<int>::size_type sz)
{
    return (s.size() > sz);
}

void biggies(vector<string> &words, vector<int>::size_type sz)
{
    sort(words.begin(), words.end());
    auto iter = unique(words.begin(), words.end());
    words.erase(iter, words.end());
    iter = stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
    for(auto i = words.begin(); i != iter; ++i){
        cout << *i << " ";
    } 
    cout << endl;
}

int main()
{
    vector<string> svec{"a", "ab", "abc", "abcd", "abcde", "abcdef", "abcdefg"};
    biggies(svec, 1);
    biggies(svec, 2);
    biggies(svec, 3);
    biggies(svec, 4);
    biggies(svec, 5);
    biggies(svec, 6);
    return 0;
}