#include <iostream>
#include <new>
#include <vector>

using namespace std;

vector<int> *factory()
{
    return new vector<int>();
}

void read(istream &is, vector<int> *pvec)
{
    int i;
    while(is >> i){
        pvec->push_back(i);
    }
}

void print(vector<int> *pvec)
{
    for(auto &i : *pvec){
        cout << i << " ";
    }
    cout << endl;
    delete pvec;
}


int main()
{
    vector<int> *pvec = factory();
    read(cin, pvec);
    print(pvec);
    return 0;
}