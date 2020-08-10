#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination *d)
{
    cout << "connected!" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "disconnected!" << endl;
}

void f(destination &d)
{
    connection c = connect(&d);
}

void end_connection(connection *p)
{
    disconnect(*p);
}

void f1(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c,end_connection);
}

int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}