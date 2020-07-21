#include <iostream>
#include <string>

using namespace std;

string::size_type myfind(string &s, string::size_type &pos, char *array, size_t len)
{
    return (s.find_first_of(array, pos, len));
}

string::size_type myfindnot(string &s, string::size_type &pos, char *array, size_t len)
{
    return (s.find_first_not_of(array, pos, len));
}

int main()
{
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char alphas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', \
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', \
    'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', \
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string s("ab2c3d7R4E6");
    string::size_type pos = 0;
    cout << "find_first_of numbers:";
    while((pos = myfind(s, pos, numbers, sizeof(numbers)/sizeof(char))) != string::npos){
        cout << s[pos] << " ";
        ++pos;
    }
    cout << endl;
    
    pos = 0;
    cout << "find_first_of alphas:";
    while((pos = myfind(s, pos, alphas, sizeof(alphas)/sizeof(char))) != string::npos){
        cout << s[pos] << " ";
        ++pos;
    }
    cout << endl;

    pos  = 0;
    cout << "find_first_not_of numbers:";
    while((pos = myfindnot(s, pos, numbers, sizeof(numbers)/sizeof(char))) != string::npos){
        cout << s[pos] << " ";
        ++pos;
    } 
    cout << endl;

    pos = 0;
    cout << "find_first_not_of alphas:";
    while((pos = myfindnot(s, pos, alphas, sizeof(alphas)/sizeof(char))) != string::npos){
        cout << s[pos] << " ";
        ++pos;
    }
    cout << endl;
    return 0;
}