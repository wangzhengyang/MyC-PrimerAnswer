#include <iostream>
#include <string>

int main()
{
    //读入两个字符串，比较其是否相等并输出结果，如果不相等，输出较大的那个字符串
    /*
    std::string s1, s2;
    getline(std::cin, s1);
    getline(std::cin, s2);
    if(s1 == s2){
        std::cout << s1 << " " << s2 << " is same!" << std::endl;
    }else if(s1 > s2){
        std::cout << s1 << " is bigger!" << std::endl;
    }else{
        std::cout << s2 << " is bigger!" << std::endl;
    }
    */

   std::string s1, s2;
   getline(std::cin, s1);
   getline(std::cin, s2);
   if(s1.size() == s2.size()){
       std::cout << s1 << " " << s2 << " has same length!" << std::endl;
   }else if(s1.size() > s2.size()){
       std::cout << s1 << " has longer length!" << std::endl;
   }else{
       std::cout << s2 << " has longer lenght" << std::endl;
   }

   return 0;
}