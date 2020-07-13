#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> &il)
{
    int sum = 0;
    for(auto iter = il.begin(); iter != il.end(); ++iter){
        sum += *iter;
    }
    return sum;
}

int main()
{
    initializer_list<int> il{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(il) << endl;
    return 0;
}