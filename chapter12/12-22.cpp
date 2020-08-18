#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr;

class StrBlob
{
friend class ConstStrBlobPtr;
public:
    StrBlob() : data(make_shared<vector<string>>()) {}
    string &front() const { return data->front(); }
    string &back() const { return data->back(); }
    void push(const string &s) { data->push_back(s); }

private:
    shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz){}
private:
    shared_ptr<vector<string>> check(size_t i, const string &s);
    size_t curr;
    weak_ptr<vector<string>> wptr;
};

int main()
{
    const StrBlob b;
    ConstStrBlobPtr pBlob(b); 
    return 0;
}