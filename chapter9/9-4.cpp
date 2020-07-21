#include <iostream>
#include <vector>

using namespace std;

bool func(vector<int>::iterator &start, vector<int>::const_iterator &end, int val)
{
    vector<int>::iterator s = start;
    for(; s < end; ++s){
        if(val == *s){
            return true;
        }
    }
    return false;
}