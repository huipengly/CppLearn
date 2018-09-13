/**
 * @brief 练习16.13
 * 
 * @file Blob.h
 * @author huipengly
 * @date 2018-09-11
 */

#ifndef _BLOB_H_
#define _BLOB_H_

#include <vector>
#include <initializer_list>
#include <memory>
#include "my_shared_ptr.h"
#include <stdexcept>

template <typename> class Blob;

template <typename T> 
    bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> 
    bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T> 
    bool operator< (const Blob<T> &, const Blob<T> &);
template <typename T> 
    bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T> 
    bool operator> (const Blob<T> &, const Blob<T> &);
template <typename T> 
    bool operator>=(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
    friend bool operator==<T>
            (const Blob<T> &, const Blob<T> &);
    friend bool operator!=<T>
            (const Blob<T> &, const Blob<T> &);
    friend bool operator< <T>
            (const Blob<T> &, const Blob<T> &);
    friend bool operator<=<T>
            (const Blob<T> &, const Blob<T> &);
    friend bool operator> <T>
            (const Blob<T> &, const Blob<T> &);
    friend bool operator>=<T>
            (const Blob<T> &, const Blob<T> &);
public:
    using size_type = typename std::vector<T>::size_type;

    Blob():data(new std::vector<T>()) { }
    Blob(std::initializer_list<T> il):data(new std::vector<T>(il)) { }
    template <typename It>
        Blob(It &b, It &e):data(new std::vector<T>(b, e)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }       // 记得使用std::move
    void pop_back() {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }

    T& front() {
        check(0, "front on empty Blob");
        return data->front();
    }

    T& back() {
        check(0, "back on empty Blob");
        return data->back();
    }

    const T& front() const {
        check(0, "front on empty Blob");
        return data->front();
    }
    const T& back() const {
        check(0, "back on empty Blob");
        return data->back();
    }

    T& operator[](std::size_t pos) { return (*data)[pos]; }
    const T& operator[](std::size_t pos) const { return (*data)[pos]; }

private:
    void check(size_type i, const T &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
   my_shared_ptr<std::vector<T>> data;
};

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return lhs.data == rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *rhs.data < *lhs.data;
}

template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs < rhs);
}

#endif
