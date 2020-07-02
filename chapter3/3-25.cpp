#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned int> scores(11, 0);
    unsigned int grade;
    auto iter = scores.begin();
    while(cin >> grade){
        cout << "grade is " << grade << endl;            
        if(grade <= 100){
            (*(iter + grade/10))++;
        }
    }
    for(auto i : scores){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}