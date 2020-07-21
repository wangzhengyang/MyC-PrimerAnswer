#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = ivec.begin();
    while (iter != ivec.end())
    {
        if (*iter % 2)
        {
            iter = ivec.insert(iter, *iter);
            iter += 2;
        }else{
            ++iter;
        }
    }
    for(auto i : ivec){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}