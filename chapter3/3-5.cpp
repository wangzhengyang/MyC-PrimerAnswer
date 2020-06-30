#include <iostream>
#include <string>

int main()
{
    //从标准输入读入多个字符串并将它们连接在一起，输出连接成的大字符串
    /*
    std::string s, temp;
    while(getline(std::cin, temp)){
        s += temp;
    }
    std::cout << s << std::endl;
    */

    //用空格把输入的多个字符串分隔开来
    std::string s, temp;
    while(getline(std::cin, temp)){
        s += temp + " ";
    }
    std::cout << s << std::endl;

    return 0;
}