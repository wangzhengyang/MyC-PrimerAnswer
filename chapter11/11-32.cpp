#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    multimap<string, string> authors = {
        {"wang", "fuck"},
        {
            "wang",
            "bigword",
        },
        {"shit", "shitword"},
    };
    for (auto &i : authors)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}