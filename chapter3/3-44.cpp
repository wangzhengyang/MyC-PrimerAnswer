#include <iostream>

using namespace std;

int ai[3][4] = {{0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}};

int main()
{
    using int_array = int[4];
    for(int_array *p = ai; p < ai + 3; ++p){
        for(int *q = *p; q < *p + 4; ++q){
            cout << *q << " ";
        }
    } 
    cout << endl;
    return 0;
}