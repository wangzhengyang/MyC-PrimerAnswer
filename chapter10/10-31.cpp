#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout);
    vector<int> ivec;

    while(in != eof){
        ivec.push_back(*in++);
    }
    sort(ivec.begin(), ivec.end());
    auto iter = unique(ivec.begin(), ivec.end());
    ivec.erase(iter, ivec.end());
    copy(ivec.begin(), ivec.end(), out);
    return 0;
}