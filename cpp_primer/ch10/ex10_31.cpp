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
using std::sort; using std::unique_copy; using std::copy;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> ivec, ivec2;

    copy(in_iter, eof, back_inserter(ivec));        // 为什么不能对流使用unique_copy，无效，还是有重复的对象
    sort(ivec.begin(), ivec.end());
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ivec2));

    for (const auto i : ivec)
    {
        cout << i << endl;
    }
    return 0;
}