#include <iostream>
#include <string>

using namespace std;

typedef string Type;
Type initVal();
class Exercise{
public:
    typedef double Type;
    Type setVal(Type); //double
    Type initVal(); //double
private:
    int val;
};

Type Exercise::setVal(Type parm) //1.string 2.double  需要将Type改成Exercise::Type
{
    val = parm + initVal();
    return val;
}