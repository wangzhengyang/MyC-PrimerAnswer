#include <iostream>

using namespace std;

class NoDefault{
public:
    NoDefault(int);
    ~NoDefault(){}
private:
};

class C{
public:
    C():d(0){}
    ~C(){}
private:
    NoDefault d;
};