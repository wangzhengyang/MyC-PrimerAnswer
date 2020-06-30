#include <iostream>
#include <string>

//效果一样

int main()
{
    std::string s(300, 'c');
    std::cout << s << std::endl;
    for(char &c : s){
        c = 'X';
    }

    std::cout << s << std::endl;
    return 0;
}