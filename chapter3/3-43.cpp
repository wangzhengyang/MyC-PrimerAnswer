#include <iostream>

using namespace std;

int ai[3][4] = {{0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}};


int main()
{
    //版本1
    /*
    for(int(&row)[4] : ai){
        for(int &column : row){
            cout << column << " ";
        }
    }
    cout << endl;
    */
    //版本2
    /*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout << ai[i][j] << " ";
        }
    }
    cout << endl;
    */
    //版本3
    for(int(*p)[4] = ai; p < ai + 3; p++){
        for(int *i = (*p); i < (*p) + 4; i++){
            cout << *i << " ";
        }
    }
    cout << endl;
    return 0;
}