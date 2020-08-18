#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination *p)
{
    cout << "connect..." << endl;
    return connection();
}

void f1(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p){
        cout << "disconnect..." << endl;
    });
}

int main()
{
    destination d;
    f1(d);
    return 0;
}