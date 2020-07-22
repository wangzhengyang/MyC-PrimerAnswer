#include <iostream>

using namespace std;

int func(int val)
{
    auto sum = [val](int val1){return val + val1;};
    return sum(2);
}

int main()
{
    cout << func(2) << endl;
    return 0;
}