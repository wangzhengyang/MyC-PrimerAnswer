#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    do{
        cout << "Enter two string :";
        if(cin >> s1 >> s2){
            if(s1.size() < s2.size()){
                cout << s1 << endl;
            }else if(s1.size() == s2.size()){
                cout << "s1 and s2 has same size" << endl;
            }else{
                cout << s2 << endl;
            }
        }
    }while(cin);
    return 0;
}