#include <iostream>
#include <string>

using namespace std;

int main()
{
    int grade;
    string ret;
    while(cin >> grade){
        if(grade > 95){
            ret = "A++";
        }else if(grade > 85){
            ret = "A";
        }else if(grade > 75){
            ret = "B";
        }else if(grade > 60){
            ret = "C";
        }else{
            ret = "D";
        }
        cout << ret << endl;
    }
    return 0;
}