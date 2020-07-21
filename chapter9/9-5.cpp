#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator func(vector<int>::iterator &start, vector<int>::const_iterator &end, int val)
{
    vector<int>::iterator iter = start;
    for(; start != end; ++start){
        if(val == *start){
            return start;
        }
    }
    return vector<int>::iterator();
}