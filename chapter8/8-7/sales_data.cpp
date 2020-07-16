#include "sales_data.h"

using namespace std;

ifstream &read(ifstream &in, Sales_Data &data)
{
    double prize;
    in >> data.BookNo >> data.Units_sold >> prize;
    if(in){
        data.revence = data.Units_sold * prize;
    }
    return in;
}

ostream &print(ostream &os, const Sales_Data &data)
{
    cout << data.BookNo << " " << data.Units_sold << " " << data.revence << endl;
    return os;
}

ofstream &save(ofstream &on, const Sales_Data &data)
{
    on << data.BookNo << data.Units_sold << data.revence << endl;
    return on;
}