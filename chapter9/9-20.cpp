#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> lst{0, 1, 2, 3, 4, 19, 20, 8, 123, 45};
    deque<int> odd;
    deque<int> even;
    for(auto i : lst){
        if(i % 2 == 0){
            odd.push_back(i);
        }else{
            even.push_back(i);
        }
    }
    cout << "odd has elements:";
    for(auto i : odd){
        cout << i << " ";
    }
    cout << endl;
    cout << "even has elements:";
    for(auto i : even){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}