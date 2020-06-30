#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;         //0个元素
    vector<int> v2(10);     //10个元素，初始值都为0
    vector<int> v3(10, 42); //10个元素，初始值都为42 
    vector<int> v4{10};     //1个元素，初始值为10
    vector<int> v5{10, 42}; //2个元素，初始值分别为10, 42
    vector<string> v6{10};  //10个元素，默认初始化的字符串
    vector<string> v7{10, "hi"};    //10个元素，默认初始化为"hi"
    return 0;
}