#include <iostream>
#include <string>

using namespace std;

int main()
{
    string record;
    unsigned int recordcnt = 0;
    string flagstr;
    string s;
    unsigned int cnt = 0;
    if(cin >> flagstr){
        cnt++; 
        while(cin >> s){
            if(s == flagstr){
                cnt++;
            }else{
                if(cnt > recordcnt){
                    record = flagstr;
                    recordcnt = cnt;
                }
                flagstr = s;
                cnt = 1;
            }
        }
        if(recordcnt == 1){
            cout << "no same word!" << endl;
        }else{
            cout << record << " occurs " << recordcnt << " times" << endl;
        }
    }else{
        cout << "format error!" << endl;
    }
    return 0;
}