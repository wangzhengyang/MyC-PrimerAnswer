#include <iostream>
#include <vector>

using namespace std;

bool IsArrayEqual(int *arr1, int len1, int *arr2, int len2)
{
    if(len1 != len2){
        return false;
    }
    for(int i = 0; i < len1; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

bool IsVectorEqual(vector<int> &ivec1, vector<int> &ivec2)
{
    if(ivec1 == ivec2){
        return true;
    }
    return false;
}

int main()
{
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "arr1 equal arr2 is " << boolalpha << IsArrayEqual(arr1, 10, arr2, 10) << endl;
    vector<int> ivec1(10, 1);
    vector<int> ivec2(10, 1);
    cout << "ivec1 equal ivec2 is " << boolalpha << IsVectorEqual(ivec1, ivec2) << endl;

    return 0;
}