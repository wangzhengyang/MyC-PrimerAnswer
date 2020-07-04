#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //使用数组
    /*
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[8];
    int arrlen = sizeof(arr)/sizeof(int);
    cout << "arrlen is " << arrlen << endl;
    int arr2len = sizeof(arr2)/sizeof(int);
    cout << "arrlen2 is " << arr2len << endl;
    int copylen = (arrlen < arr2len)? arrlen : arr2len;
    for(int i = 0; i < copylen; i++){
        arr2[i] = arr[i];
    }
    for(auto i : arr2){
        cout << i << " ";
    }
    cout << endl;
    */
    vector<int> ivec1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec2(ivec1);
    for(auto i : ivec2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}