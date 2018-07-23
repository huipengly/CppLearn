/**
 * @brief c++ primer 5th练习10.2
 * 
 * @file ex10_2.cpp
 * @author huipengly
 * @date 2018-07-23
 */
#include <algorithm>
using std::count;
#include <list>
using std::list;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    list<string> slist{"0, 1, 0, 2, 0, 3", "hello", "world", "huipeng", "hello", "liu", "hello"};
    cout << "共有" << count(slist.cbegin(), slist.cend(), "hello") << "个hello " << endl;

    return 0;
}