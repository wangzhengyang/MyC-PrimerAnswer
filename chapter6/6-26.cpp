#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    for(int index = 1; index < argc; ++index){
        cout << string(argv[index]) << endl;
    }
    return 0;
}