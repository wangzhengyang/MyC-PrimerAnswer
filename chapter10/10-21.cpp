#include <iostream>

using namespace std;

bool ret(int &i)
{
    auto func = [&]()->bool{
        if(i == 0){
            return true;
        }else{
            --i;
            return false;
        }
    };
    cout << i << endl;
    return func();
}

int main()
{
    int i = 10;
    while(ret(i) != true);
    return 0;
}