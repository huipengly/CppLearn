#include "String.h"
#include <cstring>
#include <iostream>

std::allocator<char> String::alloc;

String::String(const char* c_str)
{
    auto data = alloc_n_copy(c_str, c_str + strlen(c_str));
    elements = data.first;
    first_free = cap = data.second;

    std::cout << "String::String(const char* c_str)" << std::endl;
}

String::String(const String &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
    
    std::cout << "String::String(const String &s)" << std::endl;
}

String::String(String &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;

    std::cout << "String::String(String &&s)" << std::endl;
}

String& String::operator=(const char* c_str)
{
    auto data = alloc_n_copy(c_str, c_str + strlen(c_str));
    free();
    elements = data.first;
    first_free = cap = data.second;

    
    std::cout << "String& String::operator=(const char* c_str)" << std::endl;

    return *this;
}

String& String::operator=(const String &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    
    std::cout << "String& String::operator=(const String &s)" << std::endl;

    return *this;
}

String& String::operator=(String &&s) noexcept
{
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;

    s.elements = s.first_free = s.cap = nullptr;

    std::cout << "String& String::operator=(String &&s)" << std::endl;

    return *this;
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char*e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//     return 0;
// }

