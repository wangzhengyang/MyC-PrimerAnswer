#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<double> dvec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    //使用0 会将devc元素强制转化为int 所以使用0.0
    cout << accumulate(dvec.cbegin(), dvec.cend(), 0.0) << endl;
    return 0;
}