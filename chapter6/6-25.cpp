#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3){
        cout << "main must have two parameter!" << endl;
        return -1;
    }
    string s;
    for(int ix = 0; ix < argc; ++ix){
        s += string(argv[ix]);
    }
    cout << s << endl;
    return 0;
}