#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    int *p = arr;
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        *(p + i) = 0;
    }
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}