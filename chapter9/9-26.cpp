#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(begin(ia), end(ia));
    list<int> lst(begin(ia), end(ia));
    for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end();)
    {
        if (*iter % 2 == 0)
        {
            iter = ivec.erase(iter);
        }else{
            ++iter;
        }
    }
    cout << "ivec has elements:";
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (list<int>::iterator iter = lst.begin(); iter != lst.end();)
    {
        if (*iter % 2 == 1)
        {
            iter = lst.erase(iter);
        }else{
            ++iter;
        }
    }
    cout << "lst has elements:";
    for (auto i : lst)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}