#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v1;              //0个元素
    for(auto iter = v1.begin(); iter != v1.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<int> v2(10);          //10个元素，初始值都为0
    for(auto iter = v2.begin(); iter != v2.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<int> v3(10, 42);      //10个元素，初始值都为42
    for(auto iter = v3.begin(); iter != v3.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<int> v4{10};          //1个元素，初始值为10
    for(auto iter = v4.begin(); iter != v4.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<int> v5{10, 42};      //2个元素，初始值分别为10, 42
    for(auto iter = v5.begin(); iter != v5.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<string> v6{10};       //10个元素，默认初始化的字符串
    for(auto iter = v6.begin(); iter != v6.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    vector<string> v7{10, "hi"}; //10个元素，默认初始化为"hi"
    for(auto iter = v7.begin(); iter != v7.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    return 0;
}