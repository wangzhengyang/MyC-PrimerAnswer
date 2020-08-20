#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    /*
    char *pc1 = "hello";
    char *pc2 = "world";
    size_t len = strlen(pc1) + strlen(pc2) + 1;
    char src[len] = {};
    char *p = strcat(src, pc1);
    printf("%s\r\n", src);
    strcat(p, pc2);
    printf("%s\r\n", src);
    cout << "len:" << len << endl;
    char *pc = new char[len]();
    for(size_t i = 0; i < len; i++){
        pc[i] = src[i];
        cout << pc[i];
    }
    cout << endl;
    delete[] p;
    */
    string s1 = "hello";
    string s2 = "world";
    string s = s1 + s2;
    size_t len = s.size();
    char *p = new char[len];
    for(size_t i = 0; i < len; ++i){
        p[i] = s[i];
        cout << p[i];
    }
    cout << endl;
    delete[] p;
    return 0;
}