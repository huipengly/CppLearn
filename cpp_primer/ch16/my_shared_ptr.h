#ifndef _MY_SHARED_PTR_H_
#define _MY_SHARED_PTR_H_

#include <iostream>

template <typename T>
class my_shared_ptr
{
public:
    my_shared_ptr(T *pointer, void (*d)(T *p) = nullptr) : p(pointer), del(d), counter(1) {}
    my_shared_ptr(const my_shared_ptr& sp) : p(sp.p), del(sp.del), counter(sp.counter) { ++counter; ++sp.counter; }
    my_shared_ptr operator=(const my_shared_ptr& sp)
    {
        free();                 // 先释放原空间
        ++sp.counter;
        counter = sp.counter;
        p = sp.p;
        del = sp.del;
    }
    void reset(T *pointer, void (*d)(T *p) = nullptr)
    {
        free();
        p = pointer;
        del = d;
    }
    void free()
    {
        if(--counter == 0)
        {
            del ? del(p) : delete p; 
            std::cout << "delete memory." << std::endl;
        }
    }
    T& operator[](std::size_t sz) { return *(p + sz); }
    const T& operator[](std::size_t sz) const { return *(p + sz); }
    T& operator*() const { return *p; }
    T *operator->() const { return & this->operator*(); }
    ~my_shared_ptr() 
    { 
        free();
    }
private:
    int counter;
    T *p;
    void (*del)(T *p);          // 函数指针
};

#endif