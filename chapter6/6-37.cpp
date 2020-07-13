#include <iostream>
#include <string>

using namespace std;

string array[10];

//类型别名
/*
typedef string Array[10];
Array& retarr(){
    for(auto &i : array){
        i = "hello";
    }
    return array;
}
*/

//尾置返回类型
/*
auto retarr() -> string (&)[10]
{
    for(auto &i : array){
        i = "world";
    }
    return array;
}
*/


//decltype类型

decltype(array)& retarr()
{
    for(auto &i : array){
        i = "shit";
    }
    return array;
}


int main()
{
    for(auto &s : retarr()){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}