/**
 * @brief c++ primer 5th 练习10.25
 * 
 * @file ex10_25.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::partition; using std::sort; using std::stable_sort; using std::for_each;
#include <functional>
using std::bind; using std::placeholders::_1;

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
 * @brief 删除句子中的重复单词
 * 
 * @param words 由vector<string>存储的一句话，每个单词使用一个string存储
 */
void elim_dumps(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

/**
 * @brief 输出一句话中长度大于等于给定长度的单词
 * 
 * @param words 由vector<string>存储的一句话，每个单词使用一个string存储
 * @param sz 单词长度
 */
void biggies(vector<string> &words, string::size_type sz)
{
    elim_dumps(words);                              // 删除重复单词
    stable_sort(words.begin(), words.end()          // 按照字典顺序和字符串长度排序
                , [](const string &str1, const string &str2){ return str1.size() < str2.size(); });
    auto it = partition(words.begin(), words.end()    // 返回第一个长度大于等于sz的迭代器
                , bind(check_size, _1, sz - 1));
    auto count = words.end() - it;                  // 有多少个单词长度大于sz
    cout << "共有" << count << "个单词长度大于等于" << sz << endl;
    for_each(it, words.end(), [](const string &str) { cout << str << ' '; });
    cout << endl;
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    biggies(svec, 5);
    return 0;
}