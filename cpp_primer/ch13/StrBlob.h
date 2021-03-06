//
//  StrBlob.h
//  Exercise 13.55
//
//  Created by pezy on 12/26/14.
//
//  Define your own version of StrBlobPtr and
//  update your StrBlob class with the appropriate friend declaration and begin and end members.
//
//  @See    ex12_02.h

#ifndef CP5_ex12_19_h
#define CP5_ex12_19_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::vector; using std::string;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    StrBlob():data(std::make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il):data(std::make_shared<vector<string>>(il)) { }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void push_back(string &&t) { data->push_back(std::move(t)); }       // 记得使用std::move
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    std::string& operator[](size_t pos) { return (*data)[pos]; }
    const std::string& operator[](size_t pos) const { return (*data)[pos]; }

private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw std::out_of_range(msg);
    }

private:
    std::shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
    friend StrBlobPtr operator+(StrBlobPtr &, size_t);
    friend StrBlobPtr operator-(StrBlobPtr &, size_t);
public:
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    string* operator->() const
    {
        return & this->operator*();
    }
    StrBlobPtr& operator++() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    StrBlobPtr operator++(int)  // ????????????????
    {
        auto ret = *this;
        ++*this;
        return ret;
    }
    StrBlobPtr& operator--() {
        --curr;
        check(curr, "decrement past first of StrBlobPtr");
        return *this;
    }
    StrBlobPtr operator--(int)
    {
        auto ret = *this;
        --*this;
        return ret;
    }
    char& operator[](size_t pos) { return (*wptr.lock())[curr][pos]; }
    const char& operator[](size_t pos) const { return (*wptr.lock())[curr][pos]; }
    
private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
StrBlobPtr operator+(StrBlobPtr &, size_t);
StrBlobPtr operator-(StrBlobPtr &, size_t);

class ConstStrBlobPtr
{
    friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator+(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
    ConstStrBlobPtr():curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz) { }
    bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }
    const string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    const string* operator->() const
    {
        return & this->operator*();
    }
    ConstStrBlobPtr& operator++() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    ConstStrBlobPtr operator++(int) {
        auto ret = *this;
        ++*this;
        return *this;
    }
    ConstStrBlobPtr& operator--() {
        --curr;
        check(curr, "decrement past first of StrBlobPtr");
        return *this;
    }
    ConstStrBlobPtr operator--(int) {
        auto ret = *this;
        --*this;
        return *this;
    }
    const char& operator[](size_t pos) const { return (*wptr.lock())[curr][pos]; }

private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};
bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator+(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

#endif
