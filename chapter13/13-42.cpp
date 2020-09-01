#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

class StrVec
{
public:
    StrVec() : start(nullptr), first_free(nullptr), end(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    void push_back(const string &);
    ~StrVec();
    size_t size() const { return first_free - start; }
    size_t capacity() const { return end - start; }
    string &print(size_t index);
private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            realloc();
    }
    void realloc();
    void free();

private:
    allocator<string> alloc;
    string *start;
    string *first_free;
    string *end;
};

string &StrVec::print(size_t index)
{
    return *(start + index);
}

StrVec::StrVec(const StrVec &svec)
{
    start = alloc.allocate(svec.end - svec.start);
    string *dest = start; string *src = svec.start;
    for(; src != svec.first_free;){
        alloc.construct(dest++, *src++);
    }
    first_free = dest;
    end = start + (svec.end - svec.start);
}

StrVec &StrVec::operator=(const StrVec &svec)
{
    string *pnew = alloc.allocate(svec.end - svec.start);
    free();
    start = pnew;
    string *dest = pnew; string *src = svec.start;
    for(;src != svec.first_free;){
        alloc.construct(dest++, *src++);
    }
    first_free = dest;
    end = start + (svec.end - svec.start);
    return (*this);
}

StrVec::~StrVec()
{
    free();
}

void StrVec::free()
{
    string *p = first_free;
    size_t i = 0;
    if (start)
    {
        for (; p != start;)
        {
            alloc.destroy(--p);
            i++;
        }
        cout << "free times:" << i << endl;
        alloc.deallocate(start, end - start);
    }
}

void StrVec::realloc()
{
    size_t sz = size() ? 2 * size() : 1;
    string *pnew = alloc.allocate(sz);
    string *dest = pnew;
    string *src = start;
    for (size_t i = 0; i < size(); ++i)
    {
        alloc.construct(dest++, std::move(*src++));
    }
    free();
    start = pnew;
    first_free = dest;
    end = pnew + sz;
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

class QueryResult;

class TextQuery
{
public:
    TextQuery():p(nullptr){}
    ~TextQuery(){}
    QueryResult query(const string&);
    void read(ifstream &infile);
private:
    shared_ptr<StrVec> p;
    map<string, shared_ptr<set<int>>> mp;
};

void TextQuery::read(ifstream &infile)
{
    string line, word;
    size_t linenumber = 0;
    while(getline(infile, line)){
        
        if(p == nullptr){
            p = make_shared<StrVec>();
        }
        
        linenumber++;
        p->push_back(line);
        istringstream is(line);
        while(is >> word){
            if(mp[word] == nullptr){
                mp[word] = make_shared<set<int>>();
            }
            mp[word]->insert(linenumber);
        }
    }
    
}

class QueryResult{
public:
    QueryResult(const string &s,shared_ptr<StrVec> psvec = nullptr, shared_ptr<set<int>> pst = nullptr):content(s), p(psvec), st(pst){}
    QueryResult &operator=(const QueryResult &);
    ~QueryResult(){}
    void print();
private:
    string content;
    shared_ptr<StrVec> p;
    shared_ptr<set<int>> st;
};

QueryResult TextQuery::query(const string &s)
{
    auto iter = mp.find(s);
    if(iter == mp.end()){
        return QueryResult(s, make_shared<StrVec>(), shared_ptr<set<int>>());
    }
    return QueryResult(s, p, mp[s]);
    
}

QueryResult &QueryResult::operator=(const QueryResult &res)
{
    content = res.content;
    p = res.p;
    st = res.st;
    return (*this);
}

void QueryResult::print()
{
    
    if(st){
        cout << content << " occures " << st->size() << " times" << endl;
        for(auto i = st->cbegin(); i != st->cend(); ++i){
            cout << "line:" << *i;
            cout << p->print(*i - 1) << endl;
        }
    }
    
}



int main()
{
    
    ifstream infile("test.txt");
    TextQuery tq;
    tq.read(infile);
    string word;
    while(cin >> word){
        QueryResult res = tq.query(word);
        res.print();
    }
    
    return 0;
}