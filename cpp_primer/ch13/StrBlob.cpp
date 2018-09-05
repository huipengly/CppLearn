#include "StrBlob.h"

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    // 不需要判断大小，因为判断指针也很快
    // if (lhs.size() != rhs.size())
    // {
    //     return false;
    // }
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    // vector<string>可以直接按照字典序比较大小
    return *rhs.data < *lhs.data;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    // 不需要判断指针，因为逻辑上认为是在同指针才判断
    // return (lhs.curr == rhs.curr) && (lhs.wptr.lock() == rhs.wptr.lock());
    return lhs.curr == rhs.curr;
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

StrBlobPtr operator+(StrBlobPtr &lhs, size_t rhs)
{
    lhs.curr += rhs;
    lhs.check(lhs.curr, "increment past end of StrBlobPtr");
    return lhs;
}

StrBlobPtr operator-(StrBlobPtr &lhs, size_t rhs)
{
    lhs.curr -= rhs;
    lhs.check(lhs.curr, "decrement past first of StrBlobPtr");
    return lhs;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    // return (lhs.curr == rhs.curr) && (lhs.wptr.lock() == rhs.wptr.lock());
    return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(rhs < lhs);
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs < rhs);
}