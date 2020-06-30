#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<string> > ivec; //正确
    vector<string> svec = ivec; //错误，类型不匹配
    vector<string> svec(10, "null"); //正确
    return 0;
}