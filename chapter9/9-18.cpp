#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    string s;
    deque<string> deq;
    while(cin >> s){
        deq.push_back(s);
    }
    for(auto &s : deq){
        cout << s << endl;
    }
    return 0;
}