#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    cout << "init's capacity is:" << ivec.capacity() << endl;
    for(int i = 1; i <= 100; i++){
        ivec.push_back(i);
        cout << i << ". capacity is:" << ivec.capacity() << endl;
    }
    return 0;
}