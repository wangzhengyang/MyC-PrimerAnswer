#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    stack<char> stk;
    char c;
    bool leftbraket = false;
    while(cin >> c){
       if(c == '('){
           leftbraket = true;
       } 
       if(true == leftbraket){
           stk.push(c);
       }
       if(c == ')'){
           break;
       }
    }
    string s;
    while((c = stk.top()) != '('){
        s += c;
        stk.pop();
    }
    s += c;
    stk.pop();
    stk.push('A');
    cout << s << endl;
    return 0;
}