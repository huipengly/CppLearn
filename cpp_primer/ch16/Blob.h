/**
 * @brief ��ϰ16.13
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
#include <stdexcept>

template <typename> class Blob;
template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;

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
    // using size_type = std::vector<T>::size_type;
    typedef typename std::vector<T>::size_type size_type;
    friend class BlobPtr<T>;
    friend class ConstBlobPtr<T>;

    BlobPtr<T> begin();
    BlobPtr<T> end();
    ConstBlobPtr<T> begin() const;
    ConstBlobPtr<T> end() const;

    Blob():data(std::make_shared<std::vector<T>>()) { }
    Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)) { }

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
    std::shared_ptr<std::vector<T>> data;
};

template <typename T> 
    bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    bool operator< (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    bool operator> (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> 
    BlobPtr<T> operator+(BlobPtr<T> &, std::size_t);
template <typename T> 
    BlobPtr<T> operator-(BlobPtr<T> &, std::size_t);

template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator!=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator<=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator> <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator>=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend BlobPtr operator+<T>(BlobPtr &, std::size_t);
    friend BlobPtr operator-<T>(BlobPtr &, std::size_t);
public:
    BlobPtr():curr(0) { }
    BlobPtr(Blob<T> &a, std::size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const BlobPtr& p) { return p.curr != curr; }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    T* operator->() const
    {
        return & this->operator*();
    }
    BlobPtr& operator++() {
        check(curr, "increment past end of BlobPtr");
        ++curr;
        return *this;
    }
    BlobPtr operator++(int)
    {
        auto ret = *this;
        ++*this;
        return ret;
    }
    BlobPtr& operator--() {
        --curr;
        check(curr, "decrement past first of BlobPtr");
        return *this;
    }
    BlobPtr operator--(int)
    {
        auto ret = *this;
        --*this;
        return ret;
    }
    char& operator[](std::size_t pos) { return (*wptr.lock())[curr][pos]; }
    const char& operator[](std::size_t pos) const { return (*wptr.lock())[curr][pos]; }
    
private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const T &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound BlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T> 
    bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator!=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator< (const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator<=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator> (const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator>=(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator+ (const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
template <typename T> 
    bool operator- (const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
class ConstBlobPtr
{
    friend bool operator==<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator!=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator<=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator> <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator>=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator+ <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
    friend bool operator- <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
public:
    ConstBlobPtr():curr(0) { }
    ConstBlobPtr(const Blob<T> &a, std::size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const ConstBlobPtr& p) { return p.curr != curr; }
    const T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const T* operator->() const
    {
        return & this->operator*();
    }
    ConstBlobPtr& operator++() {
        check(curr, "increment past end of BlobPtr");
        ++curr;
        return *this;
    }
    ConstBlobPtr operator++(int) {
        auto ret = *this;
        ++*this;
        return *this;
    }
    ConstBlobPtr& operator--() {
        --curr;
        check(curr, "decrement past first of BlobPtr");
        return *this;
    }
    ConstBlobPtr operator--(int) {
        auto ret = *this;
        --*this;
        return *this;
    }
    const char& operator[](std::size_t pos) const { return (*wptr.lock())[curr][pos]; }

private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const T &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound BlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

#endif
