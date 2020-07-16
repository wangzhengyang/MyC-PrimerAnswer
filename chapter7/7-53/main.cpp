#include "debug.h"

using namespace std;

int main()
{
    constexpr Debug open(true);
    if(open.isDebug()){
        cout << "hello world!" << endl;
    }
    open.Set_DebugMode(false); //对象是常量 不能对内部变量进行更改
    if(open.isDebug()){
        cout << "hello world again!" << endl;
    }   
}