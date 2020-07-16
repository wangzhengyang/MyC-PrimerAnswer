#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>

class Person{
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