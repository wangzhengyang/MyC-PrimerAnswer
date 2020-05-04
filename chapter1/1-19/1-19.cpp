#include <iostream>

int main()
{
    int currval = 0, val = 0;
    if(std::cin >> currval){
        std::cout << std::endl;
        std::cout << currval << " ";
        val = currval;
        while(std::cin >> currval){
            if(currval > val){
                continue;
            }else{
                std::cout << currval << " ";
                val = currval;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}