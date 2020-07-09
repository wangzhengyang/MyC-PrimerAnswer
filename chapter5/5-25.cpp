#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int t1, t2;
    while (cin >> t1 >> t2)
    {
        try
        {
            if (t2 == 0)
            {
                throw runtime_error("t2 is zero!");
            }
            cout << t1 / t2 << endl;
        }
        catch (runtime_error &err)
        {
            cout << err.what() << endl;
            cout << "Please again(y/n):";
            char temp;
            cin >> temp;
            if('y' != tolower(temp)){
                break;
            }
        }
    }
    return 0;
}