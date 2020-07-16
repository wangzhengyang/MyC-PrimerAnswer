#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream &operator>>(std::istream &is, Sales_data &data);
    friend std::ostream &operator<<(std::ostream &os, Sales_data &data);
    friend std::istream &read(std::istream &is, Sales_data &data);
    friend std::ostream &print(std::ostream &os, const Sales_data &data);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
    Sales_data() = default;
    Sales_data(std::string book, unsigned int units, double prize) : bookNo(book), units_sold(units), revenue(units * prize) {}
    Sales_data(std::istream &is) { is >> *this; }
    ~Sales_data() {}
    std::string isbn() const { return bookNo; }
    Sales_data &operator+=(const Sales_data &data);
    Sales_data &operator=(const Sales_data &data);
    Sales_data &combine(const Sales_data &data);
    double avg_price(){return (revenue / units_sold);}
public:
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

#endif