/**
 * @brief 练习12.27
 * 
 * @file query_result.h
 * @author huipengly
 * @date 2018-08-24
 */
#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_

#include <iostream>
using std::ostream; using std::cout; using std::endl;
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;

class QueryResult
{
public:
    friend ostream& print(ostream &os, QueryResult qr);     //!< 打印QueryResult
    QueryResult() : times(0) {}
    QueryResult(const string &w, const int &t, shared_ptr<vector<string>> pt, shared_ptr<map<string, set<int>>> pls) :
                word(w), times(t), ptext(pt), pword_line_set(pls) {}
private:
    string word;                                            //!< 查询的单词
    int times;                                              //!< 单词出现次数
    shared_ptr<vector<string>> ptext;                       //!< 存储文本，一行为一个string
    shared_ptr<map<string, set<int>>> pword_line_set;       //!< 存储单词，和单词所在的列
};

/**
 * @brief 打印QueryResult
 * 
 * @param os 输出流类的引用，例如cout
 * @param qr 需要打印的QueryResult
 * @return ostream& 返回输出流
 */
ostream& print(ostream &os, QueryResult qr)
{
    // 判断查询的单词是否出现过
    if (qr.times > 0)
    {
        os << qr.word << " occurs " << qr.times << " times" << endl;                    // TODO：这个times需要判断单复数。
        for (auto line : (*(qr.pword_line_set))[qr.word])                               // 指针解引用之后是map<string, set<int>>
        {
            os << "    (line " << line << ") " << (qr.ptext)->at(line - 1) << endl;     // 行从1开始，vector从0开始
        }
    }
    else
    {
        os << qr.word << " doesn't occur.";
    }
    return os;      // 记得返回
}

#endif