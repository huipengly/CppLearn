/**
 * @brief c++ primer 5th 练习10.9
 * 
 * @file ex10_9.cpp
 * @author huipengly
 * @date 2018-07-23
 */
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::unique; using std::stable_sort;

/**
 * @brief 判断两个字符串长短
 * 
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @return true 第一个字符串短与第二个字符串
 * @return false 第一个字符串等于或长于第二个字符串
 */
bool is_shorter(const string &str1, const string &str2)
{
    return str1.size() < str2.size();
}

/**
 * @brief 删除重复单词
 * 
 * @param word 句子，每个string存储一个单词
 */
void elim_dumps(vector<string> &word)
{
    sort(word.begin(), word.end());
    auto end_unique = unique(word.begin(), word.end());
    word.erase(end_unique, word.end());
    stable_sort(word.begin(), word.end(), is_shorter);
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    elim_dumps(svec);
    for (auto str : svec)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}