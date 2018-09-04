/**
 * @brief StrVec类实现
 * 
 * @file StrVec.cpp
 * @author huipengly
 * @date 2018-09-03
 */
#include "StrVec.h"
#include <algorithm>
#include <iterator>

std::allocator<std::string> StrVec::alloc;      // 为静态成员分配空间

/**
 * @brief Construct a new Str Vec:: Str Vec object
 * 
 * @param l 初始化列表
 */
StrVec::StrVec(std::initializer_list<std::string> &l)
{
    auto new_data = allocate_n_copy(l.begin(), l.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 在vector后添加一个新的string
 * 
 * @param s 添加的string
 */
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

/**
 * @brief 将b到e内存的内容拷贝到新地址
 * 
 * @param b 
 * @param e 
 * @return std::pair<std::string*, std::string*> 
 */
std::pair<std::string*, std::string*> StrVec::allocate_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

/**
 * @brief 将b到e内存的内容移动到新地址
 * 
 * @param b 
 * @param e 
 * @return std::pair<std::string*, std::string*> 
 */
std::pair<std::string*, std::string*> StrVec::allocate_n_move(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(std::make_move_iterator(b), std::make_move_iterator(e), data)};
}

void StrVec::free()
{
    // 不能free空指针
    if (elements)
    {
        // // 这里销毁要逆序销毁
        // for (auto p = first_free; p != elements; --p)
        // {
        //     alloc.destroy(p);                   // 销毁每个内存中的string
        // }
        // alloc.deallocate(elements, capacity()); // 销毁分配的空间

        // ex13.43 版本
        std::for_each(elements, first_free, [](std::string &p){ alloc.destroy(&p); });  // std::string &p 这个必须是引用
    }
}

/**
 * @brief Construct a new Str Vec:: Str Vec object
 * 
 * @param s 拷贝构造使用的StrVec
 */
StrVec::StrVec(const StrVec &s)
{
    auto new_data = allocate_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 移动构造函数
 * 
 * @param s 右值
 */
StrVec::StrVec(const StrVec &&s) noexcept
{
    auto new_data = allocate_n_move(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 拷贝赋值函数
 * 
 * @param rhs 左值，赋值等号右侧
 * @return StrVec& 左值，赋值等号左侧
 */
StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto new_data = allocate_n_copy(rhs.begin(), rhs.end());
    free();                             // 与拷贝构造函数不同，这里要先free
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

/**
 * @brief 移动赋值函数
 * 
 * @param rhs 右值，赋值等号右侧
 * @return StrVec& 左值，赋值等号左侧
 */
StrVec& StrVec::operator=(const StrVec &&rhs) noexcept
{
    auto new_data = allocate_n_move(rhs.begin(), rhs.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

/**
 * @brief 申请内存，使用move的方式
 * 
 * @param sz 申请内存大小
 */
void StrVec::allocate_n_move(size_t sz)
{
    auto new_elements = alloc.allocate(sz);
    auto new_first_free = new_elements;
    for (auto p = elements; p != first_free; )
    {
        alloc.construct(new_first_free++, std::move(*p++));
    }
    free();                         //!!记得释放内存
    elements = new_elements;
    first_free = new_first_free;
    cap = new_elements + sz;
}

/**
 * @brief 重新分配空间
 * 
 */
void StrVec::reallocate()
{
    auto new_capacity = size() ? size() * 2 : 1;
    allocate_n_move(new_capacity);
}

/**
 * @brief 重新分配内存空间大小
 * 
 * @param new_cap_num 期望的内存空间大小
 */
void StrVec::reserve(size_t new_cap_num)
{
    if (new_cap_num <= capacity())          // 新size小于capacity，不改变
        return;                             
    else                                    // 新size比原来实际元素size大，改变capacity为新size，并重新分配内存
    {
        allocate_n_move(new_cap_num);
    }
}

void StrVec::resize(size_t sz, const std::string &s = "")
{
    if (size() < sz)                                        // 若当前大小小于 count ，则后附s
    {
        if (capacity() < sz)                                // 首先判断容量和sz
            reserve(sz * 2);                                // 考虑到之后的分配，大小应使用sz*2，而不是sz
        for (auto i = first_free; i != elements + sz; ++i)
        {
            alloc.construct(i, s);                          // 这里要使用分配器构造内存，不能直接赋值
        }
    }
    else if (size() > sz)                                   // 若当前大小大于 sz ，则减小容器为其首 sz 个元素。
    {
        for (auto i = first_free; i != elements + sz; --i)  // 这里应逆序销毁
        {
            alloc.destroy(i);
        }
    }
}

// int main(int argc, char const *argv[])
// {
//     return 0;
// }
