/**
 * @brief StrVec类声明
 * 
 * @file StrVec.h
 * @author huipengly
 * @date 2018-09-03
 */
#ifndef _STR_VEC_H_
#define _STR_VEC_H_
#include <memory>
#include <string>
#include <initializer_list>
#include <utility>
#include <stdexcept>
#include "my_new_delete.h"

class StrVec
{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    // @brief 默认初始化
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec&);
    StrVec(const StrVec&&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(const StrVec&&) noexcept;
    StrVec& operator=(std::initializer_list<std::string>);
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t);
    void resize(size_t, const std::string&);
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    ~StrVec() { free(); }
    std::string& at(size_t n) { if (n > size()) throw std::out_of_range("out_of_range"); return elements[n]; }
    const std::string& at(size_t n) const { if (n > size()) throw std::out_of_range("out_of_range"); return elements[n]; }
    std::string& operator[](size_t n) { return elements[n]; }
    const std::string& operator[](size_t n) const { return elements[n]; }
    template <typename... Args> void emplace_back(Args&&...);

private:
    static std::allocator<std::string> alloc;
    std::pair<std::string*, std::string*> allocate_n_copy(const std::string *b, const std::string *e);
                                                                //!< 申请空间拷贝b到e的内存
    std::pair<std::string*, std::string*> allocate_n_move(const std::string *b, const std::string *e);                                                                
    void allocate_n_move(const size_t);                         //!< 为元素分配内存
    void free();                                                //!< 释放内存
    void chk_n_alloc()                                          //!< 检查空间是否够用
        {if (size() == capacity()) reallocate(); }
    void reallocate();                                          //!< 重新分配空间
    // std::string *data;                                          //!< 保存数据 // 不需要这个，elements已经指向了数据
    std::string *elements;                                      //!< 分配内存中的首元素
    std::string *first_free;                                    //!< 最后一个实际元素之后，分配内存中第一个空闲元素
    std::string *cap;                                           //!< 分配的内存末尾之后的元素
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);


template <typename... Args>
void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc();
    // alloc.construct(first_free++, std::string(args...));
    // alloc.construct(first_free++, std::forward<Args>(args...));      // 不是扩展了给forward，而是每个单独给forward
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
#endif