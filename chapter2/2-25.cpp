#include <iostream>

using namespace std;

int main()
{
    int* ip, i, &r = i; //ip是int*指针， i是int变量， r是变量i的引用
    int i, *ip = 0;     //i是int变量， ip是int*指针，初始值为0
    int* ip, ip2;       //ip是int*指针， ip2是int变量
    return 0;
}