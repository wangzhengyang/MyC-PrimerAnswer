#include <iostream>
#include <vector>

using namespace std;

//读入一组整数并存入vector对象，将相邻的整数和输出 改写后，要求先输出第1个和最后1个元素的和，接着输出
//第2个和倒数第2个元素的和
int main()
{
    /*
    vector<int> ivec;
    int temp;
    while(cin >> temp){
        ivec.push_back(temp);
    }
    for(auto iter = ivec.begin(); iter != ivec.end() - 1; ++iter){
        cout << *iter + *(iter + 1) << " ";
    }
    cout << endl;
    */
    vector<int> ivec;
    int temp;
    while (cin >> temp)
    {
        ivec.push_back(temp);
    }
    auto iter1 = ivec.begin(), iter2 = ivec.end() - 1;
    for (; iter1 < iter2; ++iter1, --iter2)
    {
        cout << *iter1 + *iter2 << " ";
    }
    if (iter1 == iter2)
        cout << *iter1 << " ";
    cout << endl; 
    return 0;
}