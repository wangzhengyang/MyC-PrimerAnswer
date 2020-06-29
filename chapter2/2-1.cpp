#include <iostream>

using namespace::std;

/*
* int 长度 4字节
* long 长度 8字节
* long long 长度 8字节
* short 长度 2字节
* float 长度 4字节
* double 长度 8字节
*/

/*
* 无符号类型与带符号类型 数值大小范围不同
* float与double字节长度不同，然后导致精度不同
*/
int main()
{
   cout << "int size is " << sizeof(int) << endl;
   cout << "long size is " << sizeof(long) << endl;
   cout << "long long size is " << sizeof(long long) << endl;
   cout << "short size is " << sizeof(short) << endl; 
   cout << "float size is " << sizeof(float) << endl;
   cout << "double size is " << sizeof(double) << endl;
   return 0;
}