#include <iostream>
#include <set>
#include <string>

using namespace std;

bool compareString(const string &s1, const string &s2)
{
    return (s1.size() < s2.size());
}

multiset<string, bool(*)(const string&, const string&)> bookstore(compareString);

int main()
{
    return 0;
}
