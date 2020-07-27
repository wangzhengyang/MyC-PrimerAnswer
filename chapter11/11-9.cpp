#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

typedef string Word;
typedef int Line;

int main()
{
    map<Word, list<Line> > wline;
    wline["hello"].push_back(10);
    wline["hello"].push_back(20);
    wline["hello"].push_back(30);
    wline["hello"].push_back(40);
    wline["hello"].push_back(50);
    for(auto &i : wline){
        cout << i.first << " lines: ";
        for(auto &j : i.second){
            cout << j << " ";
        }
    }
    cout << endl;
    return 0;
}