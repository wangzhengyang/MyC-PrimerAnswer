#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(cin, line)){
        PersonInfo info;
        record.clear();     //清空原有绑定
        record.str(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for(auto &person : people){
        cout << person.name << " ";
        for(auto &number : person.phones){
            cout << number << " ";
        } 
        cout << endl;
    }
    return 0;
}