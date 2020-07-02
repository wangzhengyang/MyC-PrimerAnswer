#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //vector<int> ivec; //错误，ivec还没有分配
    vector<int> ivec(1);
    ivec[0] = 42;  
    return 0;
}
