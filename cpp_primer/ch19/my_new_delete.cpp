#include "my_new_delete.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
using namespace std;

void* operator new(std::size_t sz)
{
    cout << "my new" << endl;
    if (void *mem = malloc(sz))
        return mem;
    else
        throw bad_alloc();
}

// 这个delete在vs里可以进入，在gcc进不去，没有尝试在gcc调试
void operator delete(void* mem) noexcept
{
    cout << "my delete" << endl;
    free(mem);
}