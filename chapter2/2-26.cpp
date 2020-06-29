#include <iostream>

using namespace std;

int main()
{
    const int buf; //未初始化
    int cnt = 0; //可以
    const int sz = cnt; //可以 将当前cnt的值拷贝给sz
    ++cnt; ++sz;    //sz常量无法自增
    return 0;
}