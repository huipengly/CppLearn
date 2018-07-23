/**
 * @brief c++ primer 5th 练习10.13
 * 
 * @file ex10_13.cpp
 * @author huipengly
 * @date 2018-07-23
 */
#include <algorithm>
using std::partition;
#include <string>
using std::string;
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;

/**
 * @brief 判断字符串长度是否大于4
 * 
 * @param str 字符串
 * @return true 字符串长度大于4
 * @return false 字符串长度小于等于4
 */
bool size_longer_than_four(const string &str)
{
    return str.size() < 5 ? true : false;
}

int main()
{
    list<string> slist{"using", "include", "an", "the", "bool", "double", "ubuntu"};
    auto end_of_true = partition(slist.begin(), slist.end(), size_longer_than_four);
    for (auto it = end_of_true; it != slist.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}