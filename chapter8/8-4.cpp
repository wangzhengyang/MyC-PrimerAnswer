#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> svec;
    string s;
    if(argc != 2){
        cout << "err format" << endl;
    } 
    ifstream input(argv[1]);
    while(getline(input, s)){
        svec.push_back(s);
    }
    for(auto &s : svec){
        cout << s << endl;
    }
    return 0;
}