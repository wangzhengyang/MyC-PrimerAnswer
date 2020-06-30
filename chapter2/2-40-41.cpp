#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Sales_data{
friend ostream &operator<<(ostream &os, const Sales_data &data);
friend istream &operator>>(istream &is, Sales_data &data);
public:
    Sales_data() = default;
    Sales_data(istream &is){is >> *this;}
    Sales_data(const string &bookno):bookNo(bookno){}
    ~Sales_data(){}
    string ISBN()const{return bookNo;}
    Sales_data &operator+=(const Sales_data &data);
private:
    string bookNo;                      //名字
    unsigned int units_sold = 0;        //个数
    double revence = 0.0;               //总金额
};

ostream &operator<<(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revence << endl;
    return os;
}

istream &operator>>(istream &is, Sales_data &data)
{
    double price = 0.0;
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
    return *this;
}

Sales_data operator+(const Sales_data &data1, const Sales_data &data2)
{
    Sales_data ret(data1);
    ret += data2;
    return ret;
}

bool CompareISBN(const Sales_data &data1, const Sales_data &data2)
{
    return (data1.ISBN() == data2.ISBN());
}
int main()
{
//编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和
/*
    Sales_data data1(cin);
    Sales_data data2(cin);
    if(CompareISBN(data1, data2)){
        cout << data1 + data2 << endl;
    }else
    {
        cout << "not same ibsn" << endl;
    }
*/
//编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和
/*
    Sales_data total;
    if(cin >> total){
        Sales_data temp;
        while(cin >> temp){
            if(CompareISBN(total, temp)){
                total += temp;
            }else{
                cout << total << endl;
                total = temp;
            }
        }
        cout << total << endl;
    }else {
        cout << "not data input" << endl;
    }
 */
//编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录
/*
    unordered_map<string, unsigned int> map;
    Sales_data temp;
    while(cin >> temp){
        if(cin){
            map[temp.ISBN()]++;
        }
    }
    for(auto &k : map){
        cout << k.first << " has " << k.second << " records " << endl;
    }
    return 0;
*/
//输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该据在一起
    unordered_map<string, vector<Sales_data> > datamap;
    Sales_data temp;
    while(cin >> temp){
        if(cin){
            datamap[temp.ISBN()].push_back(temp);
        }
    }
    for(auto &k : datamap){
        cout << k.first << " has " << k.second.size() << " records " << endl;
        for(auto &d : k.second){
            cout << d;
        }
    }
}