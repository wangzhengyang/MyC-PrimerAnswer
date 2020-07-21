#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> lst{0, 1, 2, 3, 4};
    vector<int> ivec{0, 1, 2, 3};
    vector<int> ivec1(lst.begin(), lst.end());
    if(ivec == ivec1){
        cout << "lst's elements equal ivec's elements" << endl;
    }else{
        cout << "lst's elements not equal ivec's elements" << endl;
    }
    return 0;
}