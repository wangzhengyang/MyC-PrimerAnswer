#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto start = ivec.crbegin();
    auto end = ivec.crbegin();
    list<int> ilst(start + 2, end + 8);
    for(auto i : ilst){
        cout << i << endl;
    }
    return 0;
}