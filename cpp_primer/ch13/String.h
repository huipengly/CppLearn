#ifndef _STRING_H_
#define _STRING_H_
#include <memory>
#include <utility>
#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream&, const String&);
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    ~String() { free(); }
    String& operator=(const String&);
    String& operator=(String &&) noexcept;
    String& operator=(const char* c_str);
    // void reserve(size_t);
    // void resize(size_t);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const {return first_free; }
    void free() { delete elements; }

private:
    char *elements;
    char *first_free;
    char *cap;
    static std::allocator<char> alloc;

    std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);
    // void alloc_n(const size_t);
    // void reallocate();
    // void chk_n_alloc()
    //     { if (size() == capacity()) reallocate();}
};

std::ostream &operator<<(std::ostream &os, const String &s);        // 必须在这个文件中声明这个函数，不能只有friend

#endif