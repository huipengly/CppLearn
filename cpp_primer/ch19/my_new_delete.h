#ifndef _MY_NEW_DELETE_H_
#define _MY_NEW_DELETE_H_

#include <cstddef>

void* operator new(std::size_t sz);

void operator delete(void* mem) noexcept;

#endif