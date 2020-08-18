#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<int> ilst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto iter = ilst.cbegin(); iter != ilst.cend(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    auto start = ilst.cend();
    --start;
    for(;start != ilst.cbegin(); --start){
        cout << *start << " ";
    }
    cout << endl;

    auto s = ivec.cbegin();
    for(int i = 0; i < ivec.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}