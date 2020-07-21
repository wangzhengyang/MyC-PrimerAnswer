#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> ivec{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int sum = 0;
    for(auto i : ivec){
        sum += stoi(i);
    }
    cout << "from 1 to 9 sum is:" << sum << endl;
    vector<string> dvec{"1.1", "2.2", "3.3", "4.4", "5.5", "6.6", "7.7", "8.8", "9.9"};
    double dsum = 0;
    for(auto d : dvec){
        dsum += stod(d);
    } 
    cout << "from 1.1 to 9.9 sum is:" << dsum << endl;
    return 0;
}