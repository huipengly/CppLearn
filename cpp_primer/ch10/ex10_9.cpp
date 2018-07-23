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
using std::sort; using std::unique;

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