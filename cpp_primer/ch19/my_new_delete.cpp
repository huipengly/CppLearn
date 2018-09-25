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

void operator delete(void* mem) noexcept
{
    cout << "my delete" << endl;
    free(mem);
}