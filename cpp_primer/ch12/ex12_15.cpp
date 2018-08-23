/**
 * @brief 练习12.15
 * 
 * @file ex12_15.cpp
 * @author huipengly
 * @date 2018-08-23
 */
#include <memory>
using std::shared_ptr;

struct destination {};
struct connection {};
connection connect(destination*) {};
void disconnect(connection) {};
void end_connect(connection *p)
{
    disconnect(*p);
}
void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
}

int main()
{
    destination d;
    f(d);
    return 0;
}