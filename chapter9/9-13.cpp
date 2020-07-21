#include <iostream>
#include <vector>
#include <list>

using namespace std;

//使用迭代器初始化

int main()
{
    list<int> lst{0, 1, 2, 3};
    vector<double> dvec(lst.begin(), lst.end());
    for(auto &i : dvec){
        cout << i << " ";
    }
    cout << endl;
    vector<int> ivec{0, 1, 2, 3, 4};
    vector<double> dvec2(ivec.begin(), ivec.end());
    for(auto &i : dvec2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}