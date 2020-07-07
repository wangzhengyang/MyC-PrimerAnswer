#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int acnt = 0, icnt = 0, ecnt = 0, ocnt = 0, ucnt = 0;
    int spacecnt = 0, tabcnt = 0, linecnt = 0;
    while (getline(cin, s))
    {
        s += '\n';
        for (auto c : s)
        {
            switch (c)
            {
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
            case ' ':
                spacecnt++;
                break;
            case '\t':
                tabcnt++;
                break;
            case '\n':
                linecnt++;
                break;
            }
        }
    }
    cout << "acnt is " << acnt << endl;
    cout << "icnt is " << icnt << endl;
    cout << "ecnt is " << ecnt << endl;
    cout << "ocnt is " << ocnt << endl;
    cout << "ucnt is " << ucnt << endl;
    cout << "spacecnt is " << spacecnt << endl;
    cout << "tabcnt is " << tabcnt << endl;
    cout << "linecnt is " << linecnt << endl;
    return 0;
}