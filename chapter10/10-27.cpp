#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    vector<string> svec{"hello", "hell", "hell", "wangzhengyang", "wangzhengyang", "wangzhengyang"};
    list<string> cplst;
    unique_copy(svec.begin(), svec.end(), back_inserter(cplst));
    for(auto &s : cplst){
        cout << s << " ";
    } 
    cout << endl;
    return 0;
}