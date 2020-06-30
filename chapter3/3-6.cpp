#include <iostream>
#include <string>

int main()
{
    std::string s("hello world!");
    for(auto &c : s){
        c = 'X';
    }
    std::cout << s << std::endl;
    return 0;
}
