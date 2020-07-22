#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Sales_data{
friend ostream &operator<<(ostream &os, const Sales_data &data);
public:
    Sales_data() = default;
    Sales_data(string s, unsigned int n, double prize):bookNo(s), units_sold(n), revence(n * prize){}
    string isbn() const {return bookNo;}
private:
    string bookNo;
    unsigned int units_sold;
    double revence;
};

ostream &operator<<(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revence;
    return os;
}

bool isShort(const Sales_data &d1, const Sales_data &d2)
{
    return (d1.isbn().size() < d2.isbn().size());
}

int main()
{
    Sales_data d1("hello", 10, 1);
    Sales_data d2("hell", 2, 8);
    Sales_data d3("shit", 3, 4);
    vector<Sales_data> dvec{d1, d2, d3};
    sort(dvec.begin(), dvec.end(), isShort);
    for(auto &data : dvec){
        cout << data << endl;
    }    
    return 0;
}