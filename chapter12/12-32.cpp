#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class StrBlob
{
public:
    StrBlob(ifstream &file);
public:
    void read(ifstream &file);
    string get(size_t index) const {return ptext[index];}
    size_t size(){return ptext.size();}
private:
    vector<string> ptext;
};

StrBlob::StrBlob(ifstream &file)
{
    string line;
    while(getline(file, line)){
        ptext.push_back(line);
    }
}

void StrBlob::read(ifstream &file)
{
    string line;
    while(getline(file, line)){
        ptext.push_back(line);
    }
}

class QueryResult;
class TextQuery{
public:
    TextQuery(ifstream &file);
    ~TextQuery(){}
public:
    QueryResult query(const string &s);
private:
    shared_ptr<StrBlob> strblob;
    map<string, shared_ptr<set<size_t>>> pmap;
};

TextQuery::TextQuery(ifstream &file):strblob(new StrBlob(file))
{
    string word;
    for(size_t i = 0; i < strblob->size(); ++i){
        istringstream is(strblob->get(i));
        while(is >> word){
            if(pmap[word] == nullptr){
                pmap[word] = make_shared<set<size_t>>();
            }
            pmap[word]->insert(i + 1);
        }
    }
}

class QueryResult{
friend void print(ostream &os, const QueryResult &result);
public:
    explicit QueryResult(const string &s, shared_ptr<StrBlob> p1, shared_ptr<set<size_t>> p2):str(s), pstr(p1), ps(p2){}
    ~QueryResult(){}
private:
    string str;
    shared_ptr<StrBlob> pstr;
    shared_ptr<set<size_t>> ps;
};

QueryResult TextQuery::query(const string &s)
{
    auto index = pmap.find(s);
    if(index == pmap.end()){
        return QueryResult(s, strblob, make_shared<set<size_t>>());
    }else{
        return QueryResult(s, strblob, (*index).second);
    }
}

void print(ostream &os, const QueryResult &result)
{
    os << result.str << " occurs " << result.ps->size() << " times" << endl;
    for(auto i = result.ps->cbegin(); i != result.ps->cend(); ++i){
        cout << "(line:" << *i << ") " << result.pstr->get(*i - 1) << endl; 
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "error format" << endl;
        return -1;
    }
    ifstream file(argv[1]);
    TextQuery tp(file);

    while(true){
        cout << "enter the word you want find: ";
        string s;
        if(!(cin >> s) || s == "q"){
            break;
        }
        print(cout, tp.query(s));
    }
    return 0;
}