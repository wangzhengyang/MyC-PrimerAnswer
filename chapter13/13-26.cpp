#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob{
public:
    StrBlob();
    StrBlob(const StrBlob&);
    StrBlob &operator=(const StrBlob&);
    ~StrBlob(){}
    void push(const string &s){data->push_back(s);}
    void print();
private:
    shared_ptr<vector<string>> data;
};

StrBlob::StrBlob()
{
    data = make_shared<vector<string>>();
}

StrBlob::StrBlob(const StrBlob &s)
{
    data = make_shared<vector<string>>(*s.data);
}

StrBlob &StrBlob::operator=(const StrBlob &s)
{
    data = make_shared<vector<string>>(*s.data);
    return (*this);
}

void StrBlob::print()
{
    for(auto i = data->cbegin(); i != data->cend(); ++i){
        cout << (*i) << " ";
    }
    cout << endl;
}

int main()
{
    StrBlob b1;
    b1.push("hello");
    b1.push("world");
    StrBlob b2(b1);
    b1.push("wangzhengyang");
    b1.print();
    b2.print();
    return 0;
}

