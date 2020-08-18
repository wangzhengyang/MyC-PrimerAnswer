#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
class StrBlobPtr;

class StrBlob{
friend class StrBlobPtr;
public:
    StrBlob():data(make_shared<vector<string>>()){}
    string &front(){return data->front();}
    string &back(){return data->back();}
    void push(const string& s){data->push_back(s);}
    StrBlobPtr begin()const;
    StrBlobPtr end()const;
private:
    shared_ptr<vector<string>> data;
};

class StrBlobPtr{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(const StrBlob &a, size_t i = 0):wptr(a.data), curr(i){}
    string& deref() const;
    StrBlobPtr& incr();
    bool operator==(const StrBlobPtr& p1)const;
    bool operator!=(const StrBlobPtr& p1)const;
private:
    shared_ptr<vector<string>> check(size_t i, const string &s) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const
{
    return StrBlobPtr(*this, data->size());
}

bool StrBlobPtr::operator==(const StrBlobPtr& p1) const
{
    if(this->curr == p1.curr){
        return true;
    }else{
        return false;
    }
}

bool StrBlobPtr::operator!=(const StrBlobPtr& p1) const
{
    if(*this == p1){
        return false;
    }else{
        return true;
    }
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &s) const
{
    auto ret = wptr.lock();
    if(!ret){
        throw runtime_error("unbound StrBlobPtr");
    }
    //cout << ret->size() << endl;
    if(i >= ret->size()){
        throw out_of_range(s);
    }
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return (*this);
}

int main()
{
    StrBlob b;
    StrBlobPtr pStrBlob(b);
    b.push("wang");
    b.push("zheng");
    b.push("yang");

    for(auto i = b.begin(); i != b.end(); i.incr())
    {
        cout << i.deref() << endl;
    }
    return 0;
}