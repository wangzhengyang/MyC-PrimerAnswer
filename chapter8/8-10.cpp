#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format!" << endl;
    }
    vector<string> svec;
    string s;
    fstream in(argv[1]);
    while(getline(in, s)){
        svec.push_back(s);
    }
    in.close();
    for(auto &s : svec){
        istringstream istr(s);
        string stemp;
        while(istr >> stemp){
            cout << stemp << endl;
        }
    }
    return 0;
}