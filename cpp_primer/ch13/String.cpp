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

String& String::operator=(const char* c_str)
{
    auto data = alloc_n_copy(c_str, c_str + strlen(c_str));
    free();
    elements = data.first;
    first_free = cap = data.second;

    
    std::cout << "String& String::operator=(const char* c_str)" << std::endl;
}

String& String::operator=(const String &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    
    std::cout << "String& String::operator=(const String &s)" << std::endl;
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

