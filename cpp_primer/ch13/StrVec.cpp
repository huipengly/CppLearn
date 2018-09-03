#include "StrVec.h"

StrVec::StrVec(std::initializer_list<std::string> &l)
{
    auto new_data = allocate_n_copy(l.begin(), l.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::allocate_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // 不能free空指针
    if (elements)
    {
        // 这里销毁要逆序销毁
        for (auto p = first_free; p != elements; --p)
        {
            alloc.destroy(p);                   // 销毁每个内存中的string
        }
        alloc.deallocate(elements, capacity()); // 销毁分配的空间
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto new_data = allocate_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto new_data = allocate_n_copy(rhs.begin(), rhs.end());
    free();                             // 与拷贝构造函数不同，这里要先free
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? size() * 2 : 1;
    auto new_elements = alloc.allocate(new_capacity);
    auto new_first_free = new_elements;
    for (auto p = elements; p != first_free; )
    {
        alloc.construct(new_first_free++, std::move(*p++));
    }
    free();                         //!!记得释放内存
    elements = new_elements;
    first_free = new_first_free;
    cap = new_elements + new_capacity;
}

void StrVec::reserve(size_t new_cap_num)
{
    if (new_cap_num <= capacity())
        return;                             // 新size小于capacity，不改变
    auto new_capacity = new_cap_num;        // 新size比原来实际元素size大，改变capacity为新size，并重新分配内存
    auto new_elements = alloc.allocate(new_capacity);
    auto new_first_free = new_elements;
    auto new_cap = new_elements + new_capacity;
    for (auto p = elements; p != first_free && new_first_free != new_cap; )
    {
        alloc.construct(new_first_free++, std::move(*p++));
    }
    free();                         //!!记得释放内存
    elements = new_elements;
    first_free = new_first_free;
    cap = new_cap;
}

void StrVec::resize(size_t sz, const std::string &s = "")
{
    if (size() < sz)            // 若当前大小小于 count ，则后附s
    {
        if (capacity() < sz)    // 首先判断容量和sz
            reserve(sz * 2);        // 考虑到之后的分配，大小应使用sz*2，而不是sz
        for (auto i = first_free; i != elements + sz; ++i)
        {
            alloc.construct(i, s);      // 这里要使用分配器构造内存，不能直接赋值
        }
    }
    else if (size() > sz)       // 若当前大小大于 sz ，则减小容器为其首 sz 个元素。
    {
        for (auto i = first_free; i != elements + sz; --i)  // 这里应逆序销毁
        {
            alloc.destroy(i);
        }
    }
}

std::allocator<std::string> StrVec::alloc;

int main(int argc, char const *argv[])
{
    return 0;
}
