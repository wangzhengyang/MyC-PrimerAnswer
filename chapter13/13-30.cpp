#include <iostream>
#include <string>

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

private:
    string *ps;
};

HasPtr::HasPtr(const HasPtr &n)
{
    cout << "copy construct" << endl;
    auto temp = new string(*n.ps);
    ps = temp;
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
    cout << "operator=" << endl;
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
    HasPtr p1("wang");
    HasPtr p2("zhengyang");
    HasPtr p3("shit");
    p1.print();
    p2.print();
    swap(p1, p2);
    p1.print();
    p2.print();

    cout << endl;
    p1.print();
    p3.print();
    p3 = p1;
    p1.print();
    p3.print();
    return 0;
}