#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format" << endl;
    }
    ifstream in(argv[1]);
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(in, line)){
        PersonInfo info;
        record.clear();     //清空原有绑定
        record.str(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    in.close();
    for(auto &person : people){
        cout << person.name << " ";
        for(auto &number : person.phones){
            cout << number << " ";
        } 
        cout << endl;
    }
    return 0;
}