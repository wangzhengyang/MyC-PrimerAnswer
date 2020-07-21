#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    s.reserve(100);
    char c;
    while(cin >> c){
        s.push_back(c);
    }
    return 0;
}