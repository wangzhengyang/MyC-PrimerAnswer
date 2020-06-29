#include <iostream>

using namespace std;

int main(void)
{
    int i, *const cp; //i是int变量，cp是一个指向int的常量指针
    int i, *const cp = &i;

    int *p1, *const p2; //p1是int*指针，p2是int*的常量指针
    int *p1, *const p2 = 0x100;

    const int ic, &r = ic; //ic是int常量，r是int常量引用
    const int ic = 1, &r = ic;

    const int *const p3; //p3是指向int常量的常量指针
    const int *const p3 = &ic;

    const int *p; //可以
    
    return 0;
}