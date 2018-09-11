/**
 * @brief 实现自己的find
 * 
 */
#ifndef _MY_FIND_H_
#define _MY_FIND_H_

template <typename Iterator, typename Value>
Iterator my_find(const Iterator &beg, const Iterator &end, const Value &value)
{
    auto it = beg;
    while (it != end)
    {
        if (*it++ == value)     // Hints:每次需要让it向前移动一位
        {
            return it;
        }
    }
    return end;                 // Hints:没找到需要返回end
}

#endif