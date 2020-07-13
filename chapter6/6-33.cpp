#include <iostream>
#include <vector>

using namespace std;

void printvector(vector<int>::iterator begin, vector<int>::iterator end)
{
    if(begin == end){
        return;
    }
    cout << *begin << " ";
    printvector(++begin, end);
    return;
}

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printvector(ivec.begin(), ivec.end());
    return 0;
}