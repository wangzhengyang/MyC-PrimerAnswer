#include <iostream>
#include <vector>

using namespace std;
//在这里前置递增以及递减预算符与后置版本效果一样
int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    vector<int>::size_type cnt = ivec.size();
    //前置版本
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt){
        ivec[ix] = cnt;
    } 
    //后置版本
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ix--, cnt--){
        ivec[ix] = cnt;
    }
    return 0;
}