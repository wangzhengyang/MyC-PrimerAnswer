#include <iostream>

using namespace std;

int max(int val, int *pval)
{
    if(*pval > val){
        return *pval;
    }
    return val;
}

int main()
{
    int val = 10;
    cout << max(5, &val) << endl;
    return 0;
}