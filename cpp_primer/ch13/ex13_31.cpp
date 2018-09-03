/**
 * @brief 练习13.31
 * 
 * @file ex13_31.cpp
 * @author huipengly
 * @date 2018-09-03
 */
#include "ex13_31.h"
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <iostream>
using std::cout; using std::endl;

int main(int argc, char const *argv[])
{
    vector<HasPtr> vh;
    vh.push_back(HasPtr("1"));
    vh.push_back(HasPtr("3"));
    vh.push_back(HasPtr("2"));
    vh.push_back(HasPtr("4"));
    // for (auto h : vh)
    // {
    //     print(cout, h) << endl;
    // }
    sort(vh.begin(), vh.end());
    // for (auto h : vh)
    // {
    //     print(cout, h) << endl;
    // }
    return 0;
}
