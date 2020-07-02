#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
    vector<int> ivec;
    int temp;
    while(cin >> temp){
        ivec.push_back(temp);
    }
    for(vector<int>::size_type i = 0; i < ivec.size() - 1; i++){
        cout << ivec[i] + ivec[i + 1] << " ";
    }
    cout << endl;
    */

    vector<int> ivec;
    int temp;
    while(cin >> temp){
        ivec.push_back(temp);
    }
    vector<int>::size_type i = 0, j = ivec.size() - 1;
    for(; i < j; i++, j--){
        cout << ivec[i] + ivec[j] << " ";
    }
    if(i == j){
        cout << ivec[i] << " ";
    }
    cout << endl;
    return 0;
}