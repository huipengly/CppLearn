/**
 * @brief Vec类声明
 * 
 * @file Vec.h
 * @author huipengly
 * @date 2018-09-12
 */
#ifndef _VEC_H_
#define _VEC_H_
#include <memory>
#include <initializer_list>
#include <utility>
#include <stdexcept>

template <typename> class Vec;

template <typename T> 
    bool operator==(const Vec<T>&, const Vec<T>&);
template <typename T> 
    bool operator!=(const Vec<T>&, const Vec<T>&);
template <typename T> 
    bool operator< (const Vec<T>&, const Vec<T>&);
template <typename T> 
    bool operator<=(const Vec<T>&, const Vec<T>&);
template <typename T> 
    bool operator> (const Vec<T>&, const Vec<T>&);
template <typename T> 
    bool operator>=(const Vec<T>&, const Vec<T>&);

template <typename T>
class Vec
{
    friend bool operator==<T>(const Vec<T>&, const Vec<T>&);
    friend bool operator!=<T>(const Vec<T>&, const Vec<T>&);
    friend bool operator< <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator<=<T>(const Vec<T>&, const Vec<T>&);
    friend bool operator> <T>(const Vec<T>&, const Vec<T>&);
    friend bool operator>=<T>(const Vec<T>&, const Vec<T>&);
public:
    // @brief 默认初始化
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T>);
    Vec(const Vec&);
    Vec(const Vec&&) noexcept;
    Vec& operator=(const Vec&);
    Vec& operator=(const Vec&&) noexcept;
    Vec& operator=(std::initializer_list<T>);
    void push_back(const T&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t);
    void resize(size_t, const T&);
    T* begin() const { return elements; }
    T* end() const { return first_free; }
    ~Vec() { free(); }
    T& at(size_t n) { if (n > size()) throw std::out_of_range("out_of_range"); return elements[n]; }
    const T& at(size_t n) const { if (n > size()) throw std::out_of_range("out_of_range"); return elements[n]; }
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }

private:
    static std::allocator<T> alloc;
    std::pair<T*, T*> allocate_n_copy(const T *b, const T *e);
                                                                //!< 申请空间拷贝b到e的内存
    std::pair<T*, T*> allocate_n_move(const T *b, const T *e);                                                                
    void allocate_n_move(const size_t);                         //!< 为元素分配内存
    void free();                                                //!< 释放内存
    void chk_n_alloc()                                          //!< 检查空间是否够用
        {if (size() == capacity()) reallocate(); }
    void reallocate();                                          //!< 重新分配空间
    T *elements;                                                //!< 分配内存中的首元素
    T *first_free;                                              //!< 最后一个实际元素之后，分配内存中第一个空闲元素
    T *cap;                                                     //!< 分配的内存末尾之后的元素
};

#endif