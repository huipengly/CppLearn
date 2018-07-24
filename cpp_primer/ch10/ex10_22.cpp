/**
 * @brief c++ primer 5th 练习10.22
 * 
 * @file ex10_22.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <algorithm>
using std::count_if;
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

/**
 * @brief 检测句子中有多少单词长度小于等于给定长度
 * 
 * @param words 句子
 * @param sz 长度
 * @return int 小于等于给定长度单词的数目
 */
int smaller_than_size(const vector<string> &words, string::size_type sz)
{
    return count_if(words.begin(), words.end(), bind(check_size, _1, sz));
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    cout << smaller_than_size(svec, 6) << endl;
    return 0;
}