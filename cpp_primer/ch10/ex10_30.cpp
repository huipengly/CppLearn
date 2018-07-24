/**
 * @brief c++ primer 5th 练习10.30
 * 
 * @file ex10_30.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator; using std::back_inserter;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::copy;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> ivec;

    copy(in_iter, eof, back_inserter(ivec));
    sort(ivec.begin(), ivec.end());

    for (const auto i : ivec)
    {
        cout << i << endl;
    }
    return 0;
}