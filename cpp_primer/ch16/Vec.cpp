/**
 * @brief Vec类实现
 * 
 * @file Vec.cpp
 * @author huipengly
 * @date 2018-09-03
 */
#include "Vec.h"
#include <algorithm>
#include <iterator>

template <typename T>
    std::allocator<T> Vec<T>::alloc;      // 为静态成员分配空间

/**
 * @brief Construct a new Vec< T>:: Vec object
 * 
 * @tparam T 模板参数
 * @param li 初始化列表
 */
template <typename T>
Vec<T>::Vec(std::initializer_list<T> li)
{
    auto new_data = allocate_n_copy(li.begin(), li.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 在vector后添加一个新的T
 * 
 * @tparam T 模板参数
 * @param s 需要添加的T
 */
template <typename T>
void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

/**
 * @brief 将b到e内存的内容拷贝到新地址
 * 
 * @param b 
 * @param e 
 * @return std::pair<T*, T*> 
 */
template <typename T>
std::pair<T*, T*> Vec<T>::allocate_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

/**
 * @brief 将b到e内存的内容移动到新地址
 * 
 * @param b 
 * @param e 
 * @return std::pair<T*, T*> 
 */
template <typename T>
std::pair<T*, T*> Vec<T>::allocate_n_move(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(std::make_move_iterator(b), std::make_move_iterator(e), data)};
}

template <typename T>
void Vec<T>::free()
{
    // 不能free空指针
    if (elements)
    {
        // ex13.43 版本
        std::for_each(elements, first_free, [](T &p){ alloc.destroy(&p); });  // T &p 这个必须是引用
    }
}

/**
 * @brief Construct a new Vec< T>:: Vec object
 * 
 * @tparam T 模板参数
 * @param s 拷贝构造使用的Vec
 */
template <typename T>
Vec<T>::Vec(const Vec &s)
{
    auto new_data = allocate_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 移动构造函数
 * 
 * @tparam T 模板参数
 * @param s 右值
 */
template <typename T>
Vec<T>::Vec(const Vec &&s) noexcept
{
    auto new_data = allocate_n_move(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

/**
 * @brief 拷贝赋值函数
 * 
 * @tparam T 模板参数
 * @param rhs 左值，赋值等号右侧
 * @return Vec& 左值，赋值等号左侧
 */
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    auto new_data = allocate_n_copy(rhs.begin(), rhs.end());
    free();                             // 与拷贝构造函数不同，这里要先free
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

/**
 * @brief 使用初始化列表的赋值
 * 
 * @tparam T 模板参数
 * @param il 初始化列表
 * @return Vec& 
 */
template <typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
    auto new_data = allocate_n_copy(il.begin(), il.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

/**
 * @brief 移动赋值函数
 * 
 * @tparam T 模板参数
 * @param rhs 右值，赋值等号右侧
 * @return Vec& 左值，赋值等号左侧
 */
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &&rhs) noexcept
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
 * @tparam T 模板参数
 * @param sz 申请内存大小
 */
template <typename T>
void Vec<T>::allocate_n_move(size_t sz)
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
 * @tparam T 模板参数
 */
template <typename T>
void Vec<T>::reallocate()
{
    auto new_capacity = size() ? size() * 2 : 1;
    allocate_n_move(new_capacity);
}

/**
 * @brief 重新分配内存空间大小
 * 
 * @tparam T 模板参数
 * @param new_cap_num 期望的内存空间大小
 */
template <typename T>
void Vec<T>::reserve(size_t new_cap_num)
{
    if (new_cap_num <= capacity())          // 新size小于capacity，不改变
        return;                             
    else                                    // 新size比原来实际元素size大，改变capacity为新size，并重新分配内存
    {
        allocate_n_move(new_cap_num);
    }
}

/**
 * @brief 重设容器大小
 * 
 * @tparam T 
 * @param sz 大小
 * @param s 容器
 */
template <typename T>
void Vec<T>::resize(size_t sz, const T &s)                  // FIXME:这里原来设置了默认值，T怎么设置默认值？
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

/**
 * @brief 判断两个Vec是否相等
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true 相等
 * @return false 不相等
 */
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (auto i = 0; i != lhs.size(); ++i)
    {
        if (*(lhs.elements + i) != *(rhs.elements + i))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief 判断两个Vec是否不相等
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true 不相等
 * @return false 相等
 */
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

/**
 * @brief 判断小于
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true lhs < rhs
 * @return false lhs >= rhs
 */
template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
    auto small_size = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    for (auto i = 0; i != small_size; ++i)
    {
        if (lhs.at(i) != rhs.at(i))
        {
            return lhs.at(i) < rhs.at(i);
        }
    }
    return lhs.size() < rhs.size();
}

/**
 * @brief 判断小于等于
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true lhs <= rhs
 * @return false lhs > rhs
 */
template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(rhs < lhs);
}

/**
 * @brief 判断大于
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true lhs > rhs
 * @return false lhs <= rhs
 */
template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return rhs < lhs;
}

/**
 * @brief 判断大于等于
 * 
 * @tparam T 模板参数
 * @param lhs 
 * @param rhs 
 * @return true lhs >= rhs
 * @return false lhs < rhs
 */
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs < rhs);
}

// int main(int argc, char const *argv[])
// {
//     return 0;
// }
