#include <iostream>

using namespace std;

struct X{
    X() {cout << "X()" << endl;}
    X(const X&){cout << "X(const X&)" << endl;}
    X& operator=(const X&){cout << "X& operator=(const X&)" << endl;return (*this);}

    ~X(){cout << "~X()" << endl;}
};

void print1(X x)
{
    cout << "print1" << endl; 
}

void print2(X &x)
{
    cout << "print2" << endl;
}


int main()
{
    cout << "setp1" << endl;
    X x1;
    cout << "step2" << endl;
    X x2(x1);
    cout << "step3" << endl;
    X x3 = x1;
    x3 = x2;
    cout << "step4" << endl;
    print1(X());
    print1(x1);
    cout << "step5" << endl;
    print2(x1);
    cout << "step6" << endl;
    return 0;
}