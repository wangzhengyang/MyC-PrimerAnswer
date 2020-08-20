#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    size_t len = s.size();
    char *pc = new char[len];
    /*char *pc = new char[5];*/
    for(size_t i = 0; i < len; i++){
        pc[i] = s[i];
        cout << pc[i];
    }
    cout << endl;
    return 0;
}