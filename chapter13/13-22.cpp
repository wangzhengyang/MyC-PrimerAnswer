#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p);
    HasPtr &operator=(const HasPtr &p);
    ~HasPtr(){delete ps;}
private:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &p)
{
    auto temp = new string(*p.ps);
    delete ps;
    ps = temp;
    i = p.i;
}

HasPtr &HasPtr::operator=(const HasPtr &p)
{
    auto temp = new string(*p.ps);
    delete ps;
    ps = temp;
    i = p.i;
    return (*this);
}
