#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;
class TextResult;

class TextQuery{
public:
    TextQuery(ifstream &f);
    TextResult query(const string &s);
private:
    shared_ptr<vector<string>> ptext;
    map<string, shared_ptr<set<int>>> pmap;
};

TextQuery::TextQuery(ifstream &f)
{
    string line;
    while(getline(f, line)){
        if(ptext == nullptr){
            ptext = make_shared<vector<string>>();
        }
        ptext->push_back(line);
    }
    for(size_t i = 0; i < (*ptext).size(); ++i){
        string word;
        istringstream is((*ptext)[i]);
        while(is >> word){
            if(pmap[word] == nullptr){
                pmap[word] = make_shared<set<int>>();
            }
            pmap[word]->insert(i + 1);
        }
    }
}

class TextResult{
friend void print(const ostream &os, const TextResult &result);
public:
    explicit TextResult(const string &s, shared_ptr<vector<string>> ptext, shared_ptr<set<int>> pset):str(s), ps(ptext), pt(pset){}
private:
    string str;
    shared_ptr<vector<string>> ps;
    shared_ptr<set<int>> pt;
};

void print(const ostream &os, const TextResult& result)
{
    cout << result.str << " occurs " << result.pt->size() << " times" << endl;
    for(auto i = result.pt->cbegin(); i != result.pt->cend(); ++i){
        cout << "(line:" << *i <<"): " << (*result.ps)[*i - 1] << endl;
    }
}

TextResult TextQuery::query(const string &s)
{
    auto ret = pmap.find(s);
    if(ret == pmap.end()){
        return TextResult(s, ptext, shared_ptr<set<int>>());
    }else{
        return TextResult(s, ptext, (*ret).second);
    }
}


void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true){
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >>s) || s == "q") break;
        //打印
        print(cout, tq.query(s));
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format" << endl;
        return -1;
    }
    ifstream file(argv[1]);
    runQueries(file);
    return 0;
}