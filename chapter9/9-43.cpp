#include <iostream>
#include <string>

using namespace std;

void fuc(string &s, string &oldVal, string &newVal)
{
    for(string::iterator iter = s.begin(); iter != s.end();)
    {
        string temp(iter, iter + oldVal.size());
        if(temp == oldVal){
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size();
        }else{
            ++iter;
        }
    }
    return ;
}

int main()
{
    string s("hell world, hell wangzhengyang, hell");
    string oldVal("hell");
    string newVal("hello");
    fuc(s, oldVal, newVal);
    cout << s << endl;
    return 0;
}