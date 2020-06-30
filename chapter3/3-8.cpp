#include <iostream>
#include <string>


//使用范围for更好，因为不使用下标，这样能防止下标溢出问题，导致程序出错

int main()
{
    //传统for
    /*
    std::string s("hello world!");
    for(std::string::size_type i = 0; i < s.size(); i++){
        s[i] = 'X';
    }
    std::cout << s << std::endl;    
    */
    //传统while
    std::string s("hello world!");
    std::string::size_type i = 0;
    while(i < s.size()){
        s[i] = 'X';
        i++;
    }
    std::cout << s << std::endl;
    return 0;
}