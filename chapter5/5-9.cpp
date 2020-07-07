#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    unsigned int count = 0;
    while(getline(cin, s)){
        for(auto i : s){
            if('a' == tolower(i) || 'e' == tolower(i) || 'i' == tolower(i) || 'o' == tolower(i) || 'u' == tolower(i)){
                count++;
            }
        }
    }
    cout << "the num is " << count << endl;
    return 0;
}