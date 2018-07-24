/**
 * @brief c++ primer 5th 练习10.24
 * 
 * @file ex10_24.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <algorithm>
using std::find_if_not;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <functional>
using std::placeholders::_1; using std::bind;

/**
 * @brief 检查给定字符串长度
 * 
 * @param str 给定字符串
 * @param sz 长度
 * @return true 给定字符串长度小于等于sz
 * @return false 给定字符串长度大于sz
 */
bool check_size(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    string::size_type sz = 5;
    auto it = find_if_not(svec.begin(), svec.end(), bind(check_size, _1, sz));
    cout << *it << endl;;
    return 0;
}