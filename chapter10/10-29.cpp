#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format" << endl;
    }
    ifstream in(argv[1]);
    istream_iterator<string> iter(in), eof;
    vector<string> svec;
    while(iter != eof){
        svec.push_back(*iter++);
    }

    for(auto &s : svec){
        cout << s << endl;
    }
    return 0;
}