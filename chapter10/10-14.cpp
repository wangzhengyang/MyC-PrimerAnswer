#include <iostream>

using namespace std;

auto sum = [](int val1, int val2){return val1 + val2;};

int main()
{
    cout << sum(1, 2) << endl;
    return 0;
}