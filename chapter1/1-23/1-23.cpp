#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    Sales_item curritem;
    int salescount = 0;
    if(std::cin >> item){
        salescount = 1;
        while(std::cin >> curritem){
            if(compareIsbn(item, curritem)){
                salescount++;
            }else{
                std::cout << item.isbn() << " has " << salescount << " salesdata " << std::endl;
                item = curritem;
                salescount = 1;
            }
        }
        std::cout << item.isbn() << " has " << salescount << " salesdata " << std::endl;
    }else{
        std::cout << "has no data" << std::endl;
    }
    return 0;
}