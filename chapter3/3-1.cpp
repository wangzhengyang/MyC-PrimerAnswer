//使用恰当的using声明重做1.4.1节和2.6.2节练习

#include <iostream>

int main()
{
    //1.4.1
    //编写程序，使用while循环将50到100的整数相加
    /*
    unsigned int i = 50, sum = 0;
    while(i <= 100){
        sum += i;
        i++;
    }
    std::cout << "loop add from 50 to 100 is " << sum << std::endl;
    */
    //编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数
    /*
    int i = 10;
    while( i >= 0){
        std::cout << i-- << std::endl;
    }
    */
    //编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数
    /*
    std::cout << "please input 2 interger wiht space :";
    int start = 0, end = 0;
    std::cin >> start >> end;
    if (std::cin)
    {
        for (int i = start; i < end; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }else{
        std::cout << "input data error!" << std::endl;
    }
    */

//2.6.2 见前面编写内容，只需将cout或者cin替换为std::cout或者std::cin
    return 0;
}