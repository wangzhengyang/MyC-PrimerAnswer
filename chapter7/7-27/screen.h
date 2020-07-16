#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen{
public:
    typedef std::string::size_type  pos;
    Screen() = default;
    Screen(pos h, pos w):height(h), width(w), contents(h * w, ' '){}
    Screen(pos h, pos w, char c):height(h), width(w), contents(h * w, c){}
    Screen &move(pos h, pos w);
    Screen &set(char c);
    Screen &display(std::ostream &os);
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};

#endif