/**
 * @brief c++ primer 5th 练习14.40
 * 
 * @file ex14_40.cpp
 * @author huipengly
 * @date 2018-09-05
 */
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <algorithm>
using std::find_if; using std::sort; using std::stable_sort; using std::for_each;

class CompareTwoString
{
public:
    /**
     * @brief 比较字符串长度
     * 
     * @param str1 字符串1
     * @param str2 字符串2
     * @return true 字符串1的长度小于字符串2
     * @return false 字符串1的长度不小于字符串2
     */
    bool operator()(const string &str1, const string &str2)
    {
        return str1.size() < str2.size(); 
    }
};

class CompareSize
{
public:
    CompareSize(string::size_type sz) : sz_(sz) {}
    /**
     * @brief 比较字符串长度和sz的关系
     * 
     * @param str 字符串
     * @return true 字符串长度大于sz
     * @return false 字符串长度不大于sz
     */
    bool operator()(const string &str)
    {
        return str.size() >= sz_;
    }
private:
    string::size_type sz_;
};

class PrintString
{
public:
    PrintString(ostream &os = cout) : os_(os) {}
    /**
     * @brief 打印字符串
     * 
     * @param str 
     */
    void operator()(const string &str)
    {   
        os_ << str << endl;
    }
private:
    ostream &os_;
};

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
                , CompareTwoString());
    auto it = find_if(words.begin(), words.end()    // 返回第一个长度大于等于sz的迭代器
                , CompareSize(sz));
    auto count = words.end() - it;                  // 有多少个单词长度大于sz
    cout << "共有" << count << "个单词长度大于等于" << sz << endl;
    for_each(it, words.end(), PrintString(cout));
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    biggies(svec, 5);
    return 0;
}