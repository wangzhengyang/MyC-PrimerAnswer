#include <iostream>

void practice1()
{
    int sum = 0;
    for(int i= 50; i <= 100; i++){
        sum += i;
    }
    std::cout << sum << std::endl;
}

void practice2()
{
    for(int i = 10; i >= 0; i--){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void practice3()
{
    int start = 0, end = 0;
    std::cin >> start >> end;
    for(; start <= end; start++){
        std::cout << start << " ";
    }
    std::cout << std::endl;
}

int main()
{
    practice1();
    practice2();
    practice3();
    return 0;
}