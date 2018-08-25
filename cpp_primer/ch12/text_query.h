/**
 * @brief 练习12.27
 * 
 * @file text_query.h
 * @author huipengly
 * @date 2018-08-24
 */
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include "query_result.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <iostream>
using std::ostream; using std::cout; using std::endl;
#include <memory>
using std::shared_ptr; using std::make_shared;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;

class TextQuery
{
public:
    TextQuery(ifstream &);
    QueryResult query(const string &);
private:
    shared_ptr<vector<string>> ptext;                   //!< 存储文本，一行为一个string
    shared_ptr<map<string, set<int>>> pword_line_set;   //!< 存储单词，和单词所在的列
    map<string, int> word_number;                       //!< 记录单词出现次数
};


/**
 * @brief Construct a new Text Query:: Text Query object
 * 
 * @param infile 输入文件流
 * @note 根据文件流，存储文本，统计单词出现次数，出现行号
 */
TextQuery::TextQuery(ifstream &infile): 
        ptext(make_shared<vector<string>>()), 
        pword_line_set(make_shared<map<string, set<int>>>())
{
    string line;
    int line_number = 0;                            // 记录当前读取行号
    // 按行读取文件流
    while(getline(infile, line))
    {
        ++line_number;
        ptext->push_back(line);
        istringstream line_stream(line);
        string word;
        while (line_stream >> word)
        {
            (*pword_line_set)[word].insert(line_number);    //添加行号
            ++word_number[word];                            //记录出现次数
        }
    }
}

/**
 * @brief 查询单词
 * 
 * @param s 单词
 * @return QueryResult 查询结果
 */
QueryResult TextQuery::query(const string& s)
{
    if (word_number.find(s) != word_number.end())
    {
        return QueryResult(s, word_number[s], ptext, pword_line_set);
    }
    else
    {
        return QueryResult();
    }
}

#endif