#include <iostream>
#include <cstdlib>

using namespace std;

class numbered{
public:
    numbered();
    numbered(const numbered&);
public:
    size_t mysn;
};

numbered::numbered()
{
//    srand(time(0));
    mysn = rand();
    cout << mysn << endl;
}

numbered::numbered(const numbered &n)
{
    mysn = rand();
    cout << mysn << endl;
}

void f(numbered s){cout << s.mysn << endl;}
void f1(const numbered &s) {cout << s.mysn << endl;}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    f1(a);
    f1(b);
    f1(c);
    return 0;
}

