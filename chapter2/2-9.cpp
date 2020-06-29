#include <iostream>

using namespace std;

/*
* a. 必须先初始化变量，才能从cin读取参数
* b. 列表初始化如果存在数据精度的丢失编译器会报错， 可以采用d方法来初始化变量(在不考虑精度丢失的情况下)
* c. wage参数没有指定数据类型
* d. i结果为3，整数后面的精度丢失
*/

int main()
{
    int input_value;
    std::cin >> input_value;
    cout << input_value << endl;

    //int i = {3.14};
    //cout << i << endl;
    double salary, wage;
    salary = wage = 9999.99;
    int j = 3.14;
    cout << j << endl;
    return 0;
}