#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>

class Person{
friend std::istream &read(std::istream &is, Person &person);
friend std::ostream &print(std::ostream &os, const Person &person);
public:
    Person() = default;
    ~Person(){}
    std::string name() const {return Name;} //使用const 因为只是返回对象的值，不改变对象内部的值
    std::string address() const {return Address;} //使用const，理由同上
private:
    std::string Name;
    std::string Address;
};

#endif