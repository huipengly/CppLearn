#ifndef _STRING_H_
#define _STRING_H_
#include <memory>
#include <utility>

class String
{
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char*);
    String(const String&);
    ~String() { free(); }
    String& operator=(const String&);
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

#endif