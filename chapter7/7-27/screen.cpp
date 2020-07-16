#include "screen.h"

using namespace std;

Screen &Screen::move(Screen::pos h, Screen::pos w)
{
    cursor = height * (h - 1) + (w - 1);
    return (*this);
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return (*this);
}

Screen &Screen::display(ostream &os)
{
    os << contents;
    return (*this);
}