#include <iostream>
#include <string>

int main()
{
    //从标准输入一次读入一整行
    /*
    std::string line;
    getline(std::cin, line);
    std::cout << line << std::endl;
    */

    //从标准输入一次读入一个词
    std::string word;
    std::cin >> word;
    std::cout << word << std::endl;
    return 0;
}

