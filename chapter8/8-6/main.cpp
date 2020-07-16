#include "sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cout << "format error!" << endl;
    }
    ifstream in(argv[1]);
    Sales_Data data;
    while(read(in, data)){
        print(cout, data);
    }
    return 0;
}