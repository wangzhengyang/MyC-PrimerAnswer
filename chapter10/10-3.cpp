#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
    return 0;
}