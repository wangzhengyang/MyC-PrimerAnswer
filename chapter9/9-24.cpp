#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //vector<int> ivec{0, 1, 2, 3, 4};
    vector<int> ivec;
    cout << "at is :" << ivec.at(0) << endl;
    cout << "[0] is :" << ivec[0] << endl;
    cout << "front is :" << ivec.front() << endl;
    cout << "begin is :" << *ivec.begin() << endl;
    return 0;
}