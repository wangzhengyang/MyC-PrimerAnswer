#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    string s;
    string sought = "end";
    while(cin >> s && s != sought){}
    assert(cin);
    return 0;
}