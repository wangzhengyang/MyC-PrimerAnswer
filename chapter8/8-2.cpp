#include <iostream>

using namespace std;

istream &read(istream &is)
{
    char c;
    while(is >> c) cout << c;
    is.clear();
    return is;
}

int main()
{
    read(cin);
    return 0;
}