#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p(new int());
    unique_ptr<int> p2(p);
    unique_ptr<int> p3 = p;
    return 0;
}