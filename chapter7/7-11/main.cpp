#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data temp1;
    Sales_data temp2("hello", 10, 1);
    print(cout, temp1);
    print(cout, temp2);
    return 0;
}