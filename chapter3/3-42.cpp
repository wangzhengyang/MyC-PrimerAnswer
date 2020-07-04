#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4};
    int arr[100] = {0};
    for(vector<int>::size_type i = 0; i < ivec.size(); i++){
        arr[i] = ivec[i];
    }
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}