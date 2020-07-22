#include <numeric>
#include <iostream>
#include <string>

using namespace std;


//运行结果相同
int main()
{
    string s1("helloworld");
    string s2("helloworld");

    cout << boolalpha << equal(s1.cbegin(), s1.cend(), s2.cbegin()) << endl;

    char a1[] = "helloworld";
    char a2[] = "helloworld";

    cout << boolalpha << equal(cbegin(a1), cend(a1), cbegin(a2)) << endl;
    return 0;
}