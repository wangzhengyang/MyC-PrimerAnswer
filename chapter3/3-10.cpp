#include <iostream>
#include <string>

int main()
{
    std::string s;
    getline(std::cin, s);
    std::string s1;
    for(auto c : s){
        if(!ispunct(c)){
            s1 += c;
        }
    }
    std::cout << s1 << std::endl;
    return 0; 
}