#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int data;
    vector<int> datavec;
    while(cin >> data){
        datavec.push_back(data);
    }
    for(auto &i : datavec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}