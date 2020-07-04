#include <iostream>

using namespace std;

int ai[3][4] = {{0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}};

int main()
{
    for(auto &row : ai){
        for(auto &column : row){
            cout << column << " ";
        }
    }
    cout << endl;
    return 0;
}