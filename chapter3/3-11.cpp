#include <iostream>
#include <string>

//c 是const char &类型
int main()
{
    const std::string s = "Keep out!";
    for(auto &c : s){

    }
    return 0;
}