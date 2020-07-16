#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
public:
    Date(unsigned char s, unsigned char m, unsigned char h, unsigned char d, \
    unsigned char mo, unsigned int y):seconds(s), minutes(m), hours(h), day(d), \
    month(mo), year(y){}
    Date():Date(0, 0, 0, 1, 1, 1997){}
    ~Date(){}
private:
    unsigned char seconds;
    unsigned char minutes;
    unsigned char hours;
    unsigned char day;
    unsigned char month;
    unsigned int year;
};

#endif