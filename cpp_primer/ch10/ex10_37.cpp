/**
 * @brief c++ primer 5th 练习10.37
 * 
 * @file ex10_37.cpp
 * @author huipengly
 * @date 2018-07-25
 */
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::copy;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilst(8-3);
    
    copy(ivec.crbegin() + 3, ivec.crbegin() + 8, ilst.begin());

    for (auto &i : ilst)
    {
        cout << i << endl;
    }

    return 0;
}