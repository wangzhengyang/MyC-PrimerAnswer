#include <iostream>
#include <cstring>

using namespace std;

char arr1[] = "hello";
char arr2[] = "world!";
char arr3[100];

int main()
{
    strcpy(arr3, arr1);
    strcat(arr3, arr2);
    cout << arr3 << endl;
    return 0; 
}
