#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    /*
    string *const p = new string[10]; 
    string s;
    string *q = p;
    while(cin >> s && q != p + 10){
        *q++ = s;
    }
    const size_t size = q - p;
    delete[] p;
    */
    allocator<string> str;
    auto const p = str.allocate(10);
    string s;
    auto q = p;
    while(cin >> s && q != p + 10){
        str.construct(q++, s);
    }
    const size_t size = q - p;
    cout << "size:" << size << endl;
    for(size_t i = 0; i < size; i++){
        cout << p[i] << endl;
    }
    while(q != p){
        str.destroy(--q);
    }
    return 0;
}