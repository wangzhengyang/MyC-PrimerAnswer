#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class StrBlob{
public:
    StrBlob():data(make_shared<vector<string>>()){}
    string &front()const {return data->front();}
    string &back()const {return data->back();}
    void push(const string& s) const {data->push_back(s);}
private:
    shared_ptr<vector<string>> data;
};

int main()
{
    StrBlob block;
    block.push("wang");
    block.push("zheng");
    block.push("yang");
    cout << block.front() << endl;
    cout << block.back() << endl;
    return 0;
}