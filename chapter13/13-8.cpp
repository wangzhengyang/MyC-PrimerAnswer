#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p);
    HasPtr &operator=(const HasPtr &p);

private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &p)
{
    ps = new string(*(p.ps));
    delete p.ps;
    i = p.i;
}

HasPtr &HasPtr::operator=(const HasPtr &p)
{
    this->ps = new string(*(p.ps));
    delete p.ps;
    this->i = p.i;
    return (*this);
}
