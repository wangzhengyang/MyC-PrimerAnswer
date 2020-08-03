#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> factory()
{
    return make_shared<vector<int>>();
}

void read(istream &is, shared_ptr<vector<int>> p)
{
    int i;
    while(is >> i){
        p->push_back(i);
    }
}

void print(shared_ptr<vector<int>> p)
{
    for(auto &i : *p){
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    shared_ptr<vector<int>> p = factory();
    read(cin, p);
    print(p);
    return 0;
}