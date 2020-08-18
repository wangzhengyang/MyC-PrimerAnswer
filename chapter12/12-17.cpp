#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    IntP p0(ix); //错误 ix不是指针
    IntP p1(pi); //合法，但是p1所指向的对象是栈对象，在释放时会出错
    IntP p2(pi2); //合法，在函数结束时，pi2所指向的对象会释放
    IntP p3(&ix); //合法，但是p3所指向的对象是栈对象，在释放时会出错
    IntP p4(new int(2048)); //正确，在函数结束时，对象会释放
    IntP p5(p2.get()); //合法，但是在过程中会会将对象释放点
}
