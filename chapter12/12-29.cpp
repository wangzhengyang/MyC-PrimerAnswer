#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format!" << endl;
    }
    ifstream infile(argv[1]);
    string line, word;
    vector<string> ptext;
    map<string, set<int>> pmap;

    while(getline(infile, line)){
        ptext.push_back(line);
    }
    for(size_t i = 0; i < ptext.size(); ++i){
        istringstream is(ptext[i]);
        while(is >> word){
            pmap[word].insert(i + 1);
        }
    }
    /*
    while(true){
        cout << "enter the word you want find: ";
        string s;
        if(!(cin >> s) || s == "q"){
            cout << "exit" << endl;
            break;
        }
        auto index = pmap.find(s);
        if(index == pmap.end()){
            cout << s << " not existed!" << endl;
        }else{
            cout << s << " occurs " << (*index).second.size() << " times" << endl;
            for(auto num : (*index).second){
                cout << "(line:" << num << ") " << ptext[num - 1] << endl;
            }
        }
    }
    */
    do{
        cout << "enter the word you want find: ";
        string s;
        if(!(cin >> s) || s == "q"){
            cout << "exit" << endl;
            break;
        }
        auto index = pmap.find(s);
        if(index == pmap.end()){
            cout << s << " not existed!" << endl;
        }else{
            cout << s << " occurs " << (*index).second.size() << " times" << endl;
            for(auto num : (*index).second){
                cout << "(line:" << num << ") " << ptext[num - 1] << endl;
            }
        }        
    }while(true);

    return 0;
}