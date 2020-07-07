#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int acnt = 0, icnt = 0, ecnt = 0, ocnt = 0, ucnt = 0;
    while (getline(cin, s))
    {
        for (auto c : s)
        {
            switch (c){
                case 'a':
                case 'A':
                    acnt++;
                    break;
                case 'i':
                case 'I':
                    icnt++;
                    break;
                case 'e':
                case 'E':
                    ecnt++;
                    break;
                case 'o':
                case 'O':
                    ocnt++;
                    break;
                case 'u':
                case 'U':
                    ucnt++;
                    break;
            }
        }
    }
    cout << "acnt is " << acnt << endl;
    cout << "icnt is " << icnt << endl;
    cout << "ecnt is " << ecnt << endl;
    cout << "ocnt is " << ocnt << endl;
    cout << "ucnt is " << ucnt << endl; 
    return 0;
}