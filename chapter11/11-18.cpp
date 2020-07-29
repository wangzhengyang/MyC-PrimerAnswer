#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> word_cout;
    map<string, int>::const_iterator map_it = word_cout.cbegin();
    while(map_it != word_cout.cend()){
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
        ++map_it;
    }
    return 0;
}