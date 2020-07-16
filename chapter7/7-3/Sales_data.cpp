#include "Sales_data.h"

using namespace std;

istream &operator>>(istream &is, Sales_data &data)
{
    double prize = 0.0;
    is >> data.bookNo >> data.units_sold >> prize;
    if(is){
        data.revenue = data.units_sold * prize;
    }
    return is;
}

ostream &operator<<(ostream &os, Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revenue;
    return os;
}

Sales_data &Sales_data::operator+=(const Sales_data &data)
{
    cout << "operator+=" << endl;
    this->units_sold += data.units_sold;
    this->revenue += data.revenue;
    return (*this);
}

Sales_data &Sales_data::combine(const Sales_data &data)
{
    this->revenue += data.revenue;
    this->units_sold += data.units_sold;
    return (*this);
}

Sales_data &Sales_data::operator=(const Sales_data &data)
{
    cout << "operator=" << endl;
    this->bookNo = data.bookNo;
    this->units_sold = data.units_sold;
    this->revenue = data.revenue;
    return (*this);
}