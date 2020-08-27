#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class HasPtr
{
friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    HasPtr(const string &s) : ps(new string(s)) {}
    HasPtr(const HasPtr&);
    HasPtr &operator=(HasPtr rhs);
    ~HasPtr() { if (ps) delete ps; }
    void print();
    bool operator<(const HasPtr&);
private:
    string *ps;

};

bool HasPtr::operator<(const HasPtr &n)
{
    cout << "operator<:" << *ps << " and " << *n.ps << endl;
    if(*ps < *n.ps){
        return true;
    }
    return false;
}

HasPtr::HasPtr(const HasPtr &n)
{
    //cout << "copy construct" << endl;
    auto temp = new string(*n.ps);
    ps = temp;
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
    //cout << "operator=" << endl;
    swap(*this, rhs);
    return (*this);
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "exchange" << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
}

void HasPtr::print()
{
    cout << *ps << endl;
}

int main()
{
    vector<HasPtr> hvec;
    hvec.push_back(HasPtr("wang"));
    hvec.push_back(HasPtr("zheng"));
    hvec.push_back(HasPtr("yang"));
    hvec.push_back(HasPtr("liu"));
    hvec.push_back(HasPtr("qin"));
    sort(hvec.begin(), hvec.end());
    return 0;
}