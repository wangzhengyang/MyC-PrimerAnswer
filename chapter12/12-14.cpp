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

void disconnect(connection *c)
{
    cout << "disconnect..." << endl;
}

void f(destination &d)
{
    connection c = connect(&d);
}

void f1(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, disconnect);
}

int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}