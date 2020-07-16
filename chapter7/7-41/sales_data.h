#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data{
public:
    Sales_data(std::string s, unsigned int u, double p):BookNo(s), units_sold(u), revence(u * p)
    {
        std::cout << "Sales_data(string, unsigned int, double)" << std::endl;
    }
    Sales_data():Sales_data("", 0, 0){
        std::cout << "Sales_data()" << std::endl;
    }
    Sales_data(std::string s):Sales_data(s, 0, 0){
        std::cout << "Sales_data(string)" << std::endl;
    }

private:
    std::string BookNo;
    unsigned int units_sold = 0;
    double revence = 0.0;
};

#endif