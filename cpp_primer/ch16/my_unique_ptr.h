#ifndef _MY_UNIQUE_PTR_
#define _MY_UNIQUE_PTR_

#include "DebugDelete.h"

template <typename T, typename Del = DebugDelete>
class my_unique_ptr
{
public:
    my_unique_ptr() : p(nullptr) {}
    my_unique_ptr(T *pointer) : p(pointer) {}
    my_unique_ptr operator=(const my_unique_ptr &) = delete;
    T& operator*() { return *p; }
    const T& operator*() const { return *p; }
    T* operator->() const { return & this->operator*(); }
    ~my_unique_ptr()
    {
        del(p);
    }
private:
    T *p;
    Del del;
};

#endif