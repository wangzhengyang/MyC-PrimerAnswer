#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
friend std::ostream &operator<<(std::ostream &os, const Sales_data &data);
friend std::istream &operator>>(std::istream &is, Sales_data &data);
public:
    Sales_data() = default;
    Sales_data(const std::string name):bookNo(name){}
    ~Sales_data(){}

    std::string ISBN() const {return bookNo;}
    Sales_data &operator+=(const Sales_data &data); 
private:
    std::string bookNo;
    unsigned int units_sold = 0;
    double revence = 0.0;
};

std::ostream &operator<<(std::ostream &os, const Sales_data &data)
{
    os << data.bookNo << data.units_sold << data.revence;
    return os;
}

std::istream &operator>>(std::istream &is, Sales_data &data)
{
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    if(is){
        data.revence = data.units_sold * price;
    }else{
        data = Sales_data();
    }
    return is;
}

Sales_data &Sales_data::operator+=(const Sales_data &data)
{
    this->units_sold += data.units_sold;
    this->revence += data.revence;
    return (*this);
}

bool CompareIBSN(const Sales_data &data1, const Sales_data &data2)
{
    return (data1.ISBN() == data2.ISBN());
}

Sales_data operator+(const Sales_data &data1, const Sales_data &data2)
{
    Sales_data ret(data1);
    ret += data2;
    return ret;
}

#endif