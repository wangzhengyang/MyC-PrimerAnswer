#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1 = {0, 1, 1, 2};
    vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int>::size_type length = (ivec1.size() < ivec2.size()) ? ivec1.size() : ivec2.size();
    bool ret = true;
    for(vector<int>::size_type i = 0; i < length; ++i){
        if(ivec1[i] != ivec2[i]){
            ret = false;
            break;
        }
    }
    cout << "result is " << boolalpha << ret << endl;
    return 0;
}