#ifndef _DEBUG_H
#define _DEBUG_H

#include <iostream>

class Debug{
public:
    constexpr Debug(bool b = true):isOpen(b){}
    bool isDebug() const {return isOpen;}
    void Set_DebugMode(bool f){isOpen = f;}
private:
    bool isOpen;
};

#endif