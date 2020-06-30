#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;         //0个元素
    cout << "v1 size is " << v1.size() << endl;
    for(auto &v : v1){
        cout << v << " ";
    }
    cout << endl;
    vector<int> v2(10);     //10个元素，初始值都为0
    cout << "v2 size is " << v2.size() << endl;
    for(auto &v : v2){
        cout << v << " ";
    }
    cout << endl;
    vector<int> v3(10, 42); //10个元素，初始值都为42 
    cout << "v3 size is " << v3.size() << endl;
    for(auto &v : v3){
        cout << v << " ";
    }
    cout << endl;
    vector<int> v4{10};     //1个元素，初始值为10
    cout << "v4 size is " << v4.size() << endl;
    for(auto &v : v4){
        cout << v << " ";
    }
    cout << endl;
    vector<int> v5{10, 42}; //2个元素，初始值分别为10, 42
    cout << "v5 size is " << v5.size() << endl;
    for(auto &v : v5){
        cout << v << " ";
    }
    cout << endl;
    vector<string> v6{10};  //10个元素，默认初始化的字符串
    cout << "v6 size is " << v6.size() << endl;
    for(auto &v : v6){
        cout << v << " ";
    }
    cout << endl;
    vector<string> v7{10, "hi"};    //10个元素，默认初始化为"hi"
    cout << "v7 size is " << v7.size() << endl;
    for(auto &v : v7){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}