#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int ffcnt = 0, flcnt = 0, ficnt = 0;
    while(getline(cin, s)){
        s += '\n';
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case 'f':
                    if(s[i + 1] == 'f'){
                        ffcnt++;
                        i++;
                    }else if(s[i + 1] == 'l'){
                        flcnt++;
                        i++;
                    }else if(s[i + 1] == 'i'){
                        ficnt++;
                        i++;
                    }
                    break;
            }
        }
    }
    cout << "ffcnt is " << ffcnt << endl;
    cout << "flcnt is " << flcnt << endl;
    cout << "ficnt is " << ficnt << endl;
    return 0;
}