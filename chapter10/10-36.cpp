#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> ilst{0, 1, 2, 3, 4, 0, 5, 6, 7, 8};
    auto iter = find(ilst.crbegin(), ilst.crend(), 0);
    for(auto i = ilst.crbegin(); i != iter; ++i){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}