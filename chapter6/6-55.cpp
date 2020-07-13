#include <iostream>
#include <vector>

using namespace std;

vector<int (*)(int, int)> ivec;

int myadd(int val1, int val2)
{
    cout << "val1 add val2 is " << val1 + val2 << endl;
    return (val1 + val2);
}

int mysub(int val1, int val2)
{
    cout << "val1 sub val2 is " << val1 - val2 << endl;
    return (val1 - val2);
}

int mymulti(int val1, int val2)
{
    cout << "val1 multi val2 is " << val1 * val2 << endl;
    return (val1 * val2);
}

int mydiv(int val1, int val2)
{
    cout << "val1 div val2 is " << val1 / val2 << endl;
    return (val1 / val2);
}

int main()
{
    ivec.push_back(myadd);
    ivec.push_back(mysub);
    ivec.push_back(mymulti);
    ivec.push_back(mydiv);
    for(auto &i : ivec){
        i(10, 5);
    }
    return 0;
}