#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//使用set无需对重复数据进行判断
void vector_set(vector<string> &svec, const string &sz)
{
    auto iter = find_if(svec.begin(), svec.end(), [sz](const string &s){return (s == sz);});
    if(iter != svec.end()){
        return;
    }
    svec.push_back(sz);
    return;
}


int main()
{
    vector<string> svec;
    vector_set(svec, "wang");
    vector_set(svec, "zheng");
    vector_set(svec, "yang");
    vector_set(svec, "wang");
    for(auto &i : svec){
        cout << i << endl;
    }
    return 0;
}