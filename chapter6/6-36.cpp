#include <iostream>
#include <string>

using namespace std;

string array[10];

string (&retarray())[10]
{
    for(auto &i : array){
        i = "hello";
    }
    return array;
}

int main()
{
    for(auto s : retarray()){
        cout << s << endl;
    }
    return 0;
}