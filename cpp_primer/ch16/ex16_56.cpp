#include <iostream>
#include "debug_rep.h"
using namespace std;

template <typename T>
void print(ostream &os, const T &t)
{
    os << t;
}

template <typename T, typename... Args>
void print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";
    print(os, rest...);         // Hints:这边是rest...不是..rest
}

template <typename... Args>
void errorMsg(ostream &os, const Args&... rest)
{
    print(os, debug_rep(rest)...);
}

int main(int argc, char const *argv[])
{
    errorMsg(cout, 1, "str", 1.2);
    return 0;
}
