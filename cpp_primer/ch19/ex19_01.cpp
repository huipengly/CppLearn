#include <stdexcept>
#include <iostream>
#include <cstdlib>
using namespace std;

void* operator new(size_t sz)
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

int main(int argc, char const *argv[])
{
    int *p = new int(10);
    cout << *p << endl;
    delete p;
    return 0;
}
