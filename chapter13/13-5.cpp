#include <iostream>
#include <string>

using namespace std;

class HasPtr{
public:
    HasPtr(const string &s = string()):ps(new string(s)), i(0){}
    HasPtr(const HasPtr &p){
        ps = new string(*(p.ps));
        delete p.ps;
        i = p.i;
    }
private:
    string *ps;
    int i;
};