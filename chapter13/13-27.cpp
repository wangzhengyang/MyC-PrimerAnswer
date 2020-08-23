#include <iostream>
#include <memory>
#include <string>

using namespace std;

class HasPtr{
public:
    HasPtr():ps(new string()), i(0), use(new size_t(1)){}
    HasPtr(const HasPtr&);
    HasPtr &operator=(const HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::HasPtr(const HasPtr &p)
{
    ps = p.ps;
    i = p.i;
    use = p.use;
    (*use)++;
}

HasPtr &HasPtr::operator=(const HasPtr &p)
{
    ++*p.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return (*this);
}

HasPtr::~HasPtr()
{
    if(--(*use) == 0){
        delete ps;
        delete use;
    }
}