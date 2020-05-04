#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum;
    Sales_item curritem;
    if(std::cin >> sum){
        while(std::cin >> curritem){
            if(sum.isbn() == curritem.isbn()){
                sum += curritem;
            }
        }
        std::cout << sum << std::endl;
    }else
    {
        std::cout << "has no item" << std::endl;
    }
    
    return 0;
}