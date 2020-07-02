#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(auto iter = ivec.begin(); iter != ivec.end(); ++iter){
       *iter = (*iter) * (*iter); 
    }
    for(auto i : ivec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}