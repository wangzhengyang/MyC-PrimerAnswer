#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>

class Person{
public:
    Person() = default;
    ~Person(){}
private:
    std::string name;
    std::string address;
};

#endif