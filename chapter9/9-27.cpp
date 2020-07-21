#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    forward_list<int>::iterator prev = flst.before_begin();
    forward_list<int>::iterator iter = flst.begin();
    for(; iter != flst.end();){
        if(*iter % 2 == 1){
            iter = flst.erase_after(prev);
        }else{
            prev = iter;
            ++iter;
        }
    }
    for(auto i : flst){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}