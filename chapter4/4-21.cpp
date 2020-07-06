#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto &i : ivec){
        if(i % 2 == 1){
            i *= i;
        }
    }
    for(auto i : ivec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}