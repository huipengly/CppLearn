#ifndef _DEBUG_DELETE_H_
#define _DEBUG_DELETE_H_

#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T> void operator()(T *p) const // 记得加const，常量也能用
    { 
        os << "deletint pointer" << std::endl;
        delete p;
    }

private:
    std::ostream &os;           // 这个地方需要是引用，流不能复制
};

#endif