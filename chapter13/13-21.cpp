#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>

using namespace std;

//如果需要对象之间需要共享数据则不需要，如果不共享数据则需要自定义

class TextQuery
{
public:
    TextQuery() = default;
    TextQuery(const TextQuery &t);
    TextQuery &operator=(const TextQuery &t);

private:
    shared_ptr<vector<string>> ptext;
    map<string, shared_ptr<set<int>>> pmap;
};

TextQuery::TextQuery(const TextQuery &t)
{
    ptext = make_shared<vector<string>>();
    for (size_t i = 0; i < t.ptext->size(); ++i)
    {
        ptext->push_back((*t.ptext)[i]);
    }
    for (auto i = t.pmap.cbegin(); i != t.pmap.end(); ++i)
    {
        pmap[(*i).first] = make_shared<set<int>>();
        for (auto j = (*i).second->cbegin(); j != (*i).second->cend(); ++j)
        {
            pmap[(*i).first]->insert(*j);
        }
    }
}

TextQuery &TextQuery::operator=(const TextQuery &t)
{
    ptext = make_shared<vector<string>>();
    for (size_t i = 0; i < t.ptext->size(); ++i)
    {
        ptext->push_back((*t.ptext)[i]);
    }
    for (auto i = t.pmap.cbegin(); i != t.pmap.end(); ++i)
    {
        pmap[(*i).first] = make_shared<set<int>>();
        for (auto j = (*i).second->cbegin(); j != (*i).second->cend(); ++j)
        {
            pmap[(*i).first]->insert(*j);
        }
    }
    return (*this);
}

class QueryResult
{
public:
    QueryResult() = default;
    QueryResult(const QueryResult&);
    QueryResult &operator=(const QueryResult&);
private:
    string name;
    shared_ptr<vector<string>> ptext;
    shared_ptr<set<int>> pset;
};

QueryResult::QueryResult(const QueryResult &t)
{
    name = t.name;
    ptext = make_shared<vector<string>>();
    for(auto i = t.ptext->cbegin(); i != t.ptext->cend(); ++i){
        ptext->push_back(*i);
    }
    pset = make_shared<set<int>>();
    for(auto i = t.pset->cbegin(); i != t.pset->cend(); ++i){
        pset->insert(*i);
    }
}

QueryResult &QueryResult::operator=(const QueryResult &t)
{
    name = t.name;
    ptext = make_shared<vector<string>>();
    for(auto i = t.ptext->cbegin(); i != t.ptext->cend(); ++i){
        ptext->push_back(*i);
    }
    pset = make_shared<set<int>>();
    for(auto i = t.pset->cbegin(); i != t.pset->cend(); ++i){
        pset->insert(*i);
    }
    return (*this);
}

int main()
{
    return 0;
}