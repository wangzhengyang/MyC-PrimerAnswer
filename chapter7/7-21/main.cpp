#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total(cin);
    if(cin){
        Sales_data trans(cin);
        do{
            if(total.isbn() == trans.isbn()){
                total = total.combine(trans);
            }else{
                print(cout, total);
                total = trans;
            }
        }while(read(cin, trans));
        print(cout, total);
    }else{
        cout << "no data!" << endl;
    }
    return 0;
}