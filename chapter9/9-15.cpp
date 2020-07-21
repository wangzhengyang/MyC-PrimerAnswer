#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1 = {0, 1, 2, 3, 4};
    vector<int> ivec2 = {0, 1, 2, 3};
    if(ivec1 == ivec2){
        cout << "ivec1 equal ivec2" << endl;
    }else{
        cout << "ivec1 not equal ivec2" << endl;
    }
}