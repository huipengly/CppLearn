#ifndef _EX13_13_H_
#define _EX13_13_H_
#include <iostream>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& opeator=(const X&)" << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
};

#endif