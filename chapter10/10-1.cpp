#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int i;
    cin >> i;
    cout << count(ivec.cbegin(), ivec.cend(), i) << endl;
    return 0;
}