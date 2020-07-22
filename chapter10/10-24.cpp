#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, int sz)
{
    return (s.size() < sz);
}

int main()
{
    string s("hello");
    vector<int> ivec{3, 4, 6, 7, 9, 10, 11, 12};
    auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
    cout << *iter << endl;
    return 0;
}
