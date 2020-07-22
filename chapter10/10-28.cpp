#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> isvec;
    copy(ivec.begin(), ivec.end(), back_inserter(isvec));
    for (auto i : isvec)
    {
        cout << i << " ";
    }
    cout << endl;
    deque<int> fisvec;
    copy(ivec.begin(), ivec.end(), front_inserter(fisvec));
    for (auto i : fisvec)
    {
        cout << i << " ";
    }
    cout << endl;
    deque<int> iisvec;
    copy(ivec.begin(), ivec.end(), inserter(iisvec, iisvec.begin()));
    for (auto i : iisvec)
    {
        cout << i << " ";
    }
    cout << endl;
    deque<int> iisvec2;
    copy(ivec.begin(), ivec.end(), inserter(iisvec2, iisvec2.end()));
    for (auto i : iisvec2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}