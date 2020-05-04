#include <iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int start = 0, end = 0;
    std::cin >> start >> end;
    for(; start <= end; start++){
        std::cout << start << " ";
    }
    std::cout << std::endl;
    return 0;
}