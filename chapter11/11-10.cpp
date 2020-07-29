#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
    map<list<int>::iterator, int> lstimap; //不可以，lstimap不支持<操作
    map<vector<int>::iterator, int> iterimap; //可以
    return 0;
}