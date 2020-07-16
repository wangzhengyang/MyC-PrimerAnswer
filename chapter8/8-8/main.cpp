#include "sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3){
        cout << "format error!" << endl;
    }
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::out | ofstream::ate | ofstream::app); 
    Sales_Data data;
    while(read(in, data)){
        save(out, data);
    }
    return 0;
}