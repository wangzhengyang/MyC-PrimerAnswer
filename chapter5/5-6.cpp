#include <iostream>
#include <string>

using namespace std;

int main()
{
    int grade;
    string ret;
    while(cin >> grade){
        ret = (grade > 95) ? "A++" : ((grade > 85) ? "A" : ((grade > 75) ? "B" : ((grade > 60) ? "C" : "D")));
        cout << ret << endl;
    }
    return 0;
}
