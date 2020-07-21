#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> cvec{'h', 'e', 'l', 'l', '0'};
    string s(&cvec[0], cvec.size());
    cout << s << endl;
    return 0;
}