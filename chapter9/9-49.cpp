#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s("bdfghijklpqty");
    string max;
    string in;
    while(cin >> in){
        auto pos = in.find_first_of(s);
        if(pos == string::npos){
            if(in.size() > max.size()){
                max = in;
            }
        }
    }
    if(max.size() == 0){
        cout << "not found!" << endl;
    }else{
        cout << max << endl;
    }
    return 0;
}