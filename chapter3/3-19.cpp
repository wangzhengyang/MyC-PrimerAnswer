#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //方法1
    vector<int> ivec1(10, 42);
    //方法2
    vector<int> ivec2(10);
    for(int &i : ivec2){
        i = 42;
    }
    //方法3
    vector<int> ivec3;
    for(int i = 0; i < 10; i++){
        ivec3.push_back(42);
    }
    return 0;
}
