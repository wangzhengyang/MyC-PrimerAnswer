//使用2.6.1定义的Sales_data类为1.6节的交易处理程序编写新版本
#include <iostream>
#include <string>

using namespace std;

class Sales_data{
friend istream &operator>>(istream &is, Sales_data &data);
friend ostream &operator<<(ostream &os, Sales_data &data);
public:
    Sales_data() = default;
    ~Sales_data(){}
    string isbn()const {return bookNo;}
    Sales_data &operator+=(Sales_data &data);
    Sales_data &operator=(Sales_data &data);
private:
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

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

Sales_data &Sales_data::operator+=(Sales_data &data)
{
    cout << "operator+=" << endl;
    this->units_sold += data.units_sold;
    this->revenue += data.revenue;
    return (*this);
}

Sales_data &Sales_data::operator=(Sales_data &data)
{
    cout << "operator=" << endl;
    this->bookNo = data.bookNo;
    this->units_sold = data.units_sold;
    this->revenue = data.revenue;
    return (*this);
}

int main()
{
    Sales_data total;
    if(cin >> total){
        Sales_data trans;
        while(cin >> trans){
            if(total.isbn() == trans.isbn()){
                total += trans;
            }else{
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }else{
        cerr << "No data!" << endl;
        return -1;
    }
    return 0;
}