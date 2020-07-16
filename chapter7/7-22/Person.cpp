#include "Person.h"

using namespace std;

istream &read(istream &is, Person &person)
{
    is >> person.Name >> person.Address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.Name << person.Address;
    return os;
}