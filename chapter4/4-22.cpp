#include <iostream>
#include <string>

using namespace std;

int main()
{
    //条件运算符
    /*
    string ret;
    int grade;
    while(cin >> grade){
        ret = (grade > 90)? "high pass" : (grade > 75)? "pass" : (grade > 60)? "low pass" : "fail";
        cout << ret << endl;
    }
    */
    //if判断
    string ret;
    int grade;
    while(cin >> grade){
        if(grade > 90){
            ret = "hight pass";
        }else if(grade > 75){
            ret = "pass";
        }else if(grade > 60){
            ret = "low pass";
        }else{
            ret = "fail";
        }
        cout << ret << endl;
    }
    return 0;
}