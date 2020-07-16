#include <iostream>
#include <sstream>

using namespace std;

ostream &print(ostream &os, istringstream &istr)
{
    os << istr.str() << endl;
    return os;
}

int main()
{
    string s("hello world!");
    istringstream istr(s);
    print(cout, istr);
    return 0;
}