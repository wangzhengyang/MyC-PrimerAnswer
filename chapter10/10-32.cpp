#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Sales_data{
friend ostream &operator<<(ostream &os, const Sales_data &data);
public:
    Sales_data() = default;
    Sales_data(const string &s, unsigned int n, double p):bookNo(s), units_sold(n), revence(n * p){};
    string isbn() const {return bookNo;}
    Sales_data &operator+(const Sales_data *pd);
private:
    string bookNo;
    unsigned int units_sold;
    double revence;
};

bool compareIsbn(const Sales_data *pd1, const Sales_data *pd2)
{
    if(pd1->isbn().size() > pd2->isbn().size()){
        return true;
    }
    return false;
}

Sales_data &Sales_data::operator+(const Sales_data *pd)
{
    this->units_sold += pd->units_sold;
    this->revence += pd->revence;
    return *this;
}

ostream &operator<<(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revence;
    return os;
}

int main()
{
    Sales_data data1("hello", 10, 1);
    Sales_data data2("hellboy", 4, 5);
    Sales_data data3("hello", 10, 2);
    Sales_data data4("hello", 10, 3);
    Sales_data data5("wangzhengyang", 6, 7);
    vector<Sales_data *> salesvec{&data1, &data2, &data3, &data4, &data5};
    sort(salesvec.begin(), salesvec.end(), compareIsbn);
    auto start = salesvec.begin();
    while(start != salesvec.end()){
        cout << "start:" << **start << endl;
        auto end = find_if(start, salesvec.end(), [start](const Sales_data *pd)->bool{
            if(pd->isbn() != (*start)->isbn()){
                return true;
            }else{
                return false;
            }
        });
        if(end == salesvec.end()){
            cout << "get end" << endl;
        }else{
            cout << "end:" << **end << endl;
        }
        auto data = accumulate(start, end, Sales_data((*start)->isbn(), 0, 0));
        cout << data << endl;
        start = end;
    }
    return 0;
}
