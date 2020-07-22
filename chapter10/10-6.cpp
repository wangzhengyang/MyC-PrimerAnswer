#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(10, 1);
    cout << "before:";
    for(auto i : ivec){
        cout << i << " ";
    }
    cout << endl;
    fill_n(ivec.begin(), ivec.size(), 0);
    cout << "after:";
    for(auto i : ivec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}