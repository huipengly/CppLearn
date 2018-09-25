#include "StrVec.h"

int main(int argc, char const *argv[])
{
    StrVec s;
    s.reserve(100);
    s.push_back("abc");
    s.push_back("def");
    s.reserve(10);
    return 0;
}
