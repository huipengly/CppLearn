#include "Blob.h"

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template <typename T>
ConstBlobPtr<T> Blob<T>::begin() const
{
    return ConstBlobPtr<T>(*this);
}

template <typename T>
ConstBlobPtr<T> Blob<T>::end() const
{
    return ConstBlobPtr<T>(*this, data->size());
}

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

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    // 不需要判断指针，因为逻辑上认为是在同指针才判断
    // return (lhs.curr == rhs.curr) && (lhs.wptr.lock() == rhs.wptr.lock());
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
BlobPtr<T> operator+(BlobPtr<T> &lhs, std::size_t rhs)
{
    lhs.curr += rhs;
    lhs.check(lhs.curr, "increment past end of BlobPtr<T>");
    return lhs;
}

template <typename T>
BlobPtr<T> operator-(BlobPtr<T> &lhs, std::size_t rhs)
{
    lhs.curr -= rhs;
    lhs.check(lhs.curr, "decrement past first of BlobPtr<T>");
    return lhs;
}

template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    // return (lhs.curr == rhs.curr) && (lhs.wptr.lock() == rhs.wptr.lock());
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return lhs.curr < rhs.curr;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}