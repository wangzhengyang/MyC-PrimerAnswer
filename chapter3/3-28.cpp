#include <iostream>
#include <string>

using namespace std;

string sa[10];  //初始化空字符串
int ia[10];     //初始化为0

int main()
{
    string sa2[10]; //初始化为空字符串
    int ia2[10];    //未初始化
    for(auto i : sa){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : ia){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : sa2){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : ia2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}