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

std::ostream &operator<<(std::ostream &os, const String &s)
{
    for (auto c : s)
        os << c;
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (auto i = lhs.size(); i != lhs.size(); ++i)
    {
        if (*(lhs.elements + i) != *(rhs.elements + i))
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    auto small_size = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    // 两边最小的长度以内若有不同字符，则返回字符比较结果
    for (auto i = 0; i != small_size; ++i)
    {
        if (*(lhs.elements + i) != *(rhs.elements + i))
        {
            return *(lhs.elements + i) < *(rhs.elements + i);
        }
    }
    // 两边最小的长度之内相同，则比较字符串长度
    return lhs.size() < rhs.size();
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//     return 0;
// }
