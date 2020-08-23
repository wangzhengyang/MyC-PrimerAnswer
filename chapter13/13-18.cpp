#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    Employee(){id = Employee::index++;}
    Employee(const string &na) : name(na) { id = Employee::index++; }
    void print() const { cout << "name:" << name << " id:" << id << endl; }
    //static size_t index;
private:
    string name;
    size_t id;
    static size_t index;
};

size_t Employee::index = 0;

int main()
{
    Employee p1;
    Employee p2("wangzhengyang");
    p1.print();
    p2.print();
    return 0;
}