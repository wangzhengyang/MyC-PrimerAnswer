#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> imap= {
        {0, 0},
        {1, 0},
        {2, 0},
    };
    for(auto iter = imap.begin(); iter != imap.end(); ++iter){
        iter->second = 1;
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}