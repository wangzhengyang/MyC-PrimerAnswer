#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool StringCompare(string s1, string s2)
{
    if(s1 == s2){
        return true;
    }
    return false;
}

bool CstringCompare(char *p1, char *p2)
{
   int ret = strcmp(p1, p2);
   if(ret == 0){
       return true;
   }
   return false;
}

int main()
{
    string s1 = "helloworld!";
    string s2 = "helloworld!";
    cout << "s1 equal s2 is " << boolalpha << StringCompare(s1, s2) << endl;
    char p1[] = "hello";
    char p2[] = "Hello";
    cout << "p1 equal p2 is " << boolalpha << CstringCompare(p1, p2) << endl;
    return 0;
}