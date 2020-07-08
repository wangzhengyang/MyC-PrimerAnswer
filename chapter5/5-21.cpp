#include <iostream>
#include <string>

using namespace std;

int main()
{
    string key;
    bool sameflag = false;
    string s;
    if(cin >> key){
        while(cin >> s){
            if(key == s){
                if(isupper(key[0])){
                    sameflag = true;
                    break;
                }else{
                    continue;
                }
            }else{
                key = s;
            }
        }
        if(sameflag){
            cout << key << endl;
        }else{
            cout << "no same word!" << endl;
        }


    }else{
        cout << "format error!" << endl;
    }
    return 0;
}