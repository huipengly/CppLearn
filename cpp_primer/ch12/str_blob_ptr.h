#ifndef _STR_BLOB_PTR_H_
#define _STR_BLOB_PTR_H_

#include "str_blob.h"
#include <memory>
using std::weak_ptr; using std::shared_ptr;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stdexcept>
using std::out_of_range; using std::runtime_error;

class StrBlob;          // 需要先声明，不然交叉引用会报错
class StrBlobPtr
{
public:
    typedef vector<string>::size_type size_type;
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    string& deref() const;          // 解引用
    StrBlobPtr& incr();             // 前缀递增
private:
    shared_ptr<vector<string>> check(const size_type &i, const string &msg) const;
    weak_ptr<vector<string>> wptr;
    size_type curr;
};

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "deref out of range");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(const size_type &i, const string &msg) const
{
    auto p = wptr.lock();
    if (!p)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= p->size())
    {
        throw out_of_range(msg);
    }
    return p;
}

#endif