#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <iostream>
#include <fstream>
#include <string>

class Sales_Data{
friend std::ifstream &read(std::ifstream &in, Sales_Data &data); 
friend std::ostream &print(std::ostream &os, const Sales_Data &data);  
public:
    Sales_Data() = default;
    ~Sales_Data(){}
private:
    std::string BookNo;
    unsigned int Units_sold;
    double revence;
};

#endif