//编译200页的str_subrange函数，看看编译器怎么处理函数中错误
#include <iostream>
#include <string>

using namespace std;

bool str_subrange(const string &str1, const string &str2)
{
    if(str1.size() == str2.size()){
        return (str1 == str2);
    }
    auto size = (str1.size() < str2.size())? str1.size() : str2.size();
    for(decltype(size) i = 0; i != size; ++i){
        if(str1[i] != str2[i]){
            return; //error:return-statement with no value
        }
    }
}

int main()
{
    string s1("hello world!");
    string s2("Hello world!");
    cout << boolalpha << str_subrange(s1, s2) << endl;
    return 0;
}