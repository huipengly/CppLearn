/**
 * @brief 文本查询类
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

/**
 * @brief 文本查询
 * 
 */
class TextQuery
{
public:
    typedef vector<int>::size_type size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &);
private:
    shared_ptr<vector<string>> ptext;                           //!< 存储文本，一行为一个string
    map<string, shared_ptr<set<size_type>>> word_line;          //!< 存储单词，和单词所在的列
    map<string, size_type> word_number;                         //!< 记录单词出现次数
};


/**
 * @brief Construct a new Text Query:: Text Query object
 * 
 * @param infile 输入文件流
 * @note 根据文件流，存储文本，统计单词出现次数，出现行号
 */
TextQuery::TextQuery(ifstream &infile): 
        ptext(make_shared<vector<string>>())
{
    string line;
    // 按行读取文件流
    while(getline(infile, line))
    {
        ptext->push_back(line);
        istringstream line_stream(line);
        string word;
        int line_number = ptext->size();    // 记录当前读取行号
        while (line_stream >> word)
        {
            auto &p = word_line[word];
            // 判断之前是否添加过word
            if (p)
            {
                // cout << "!p" << endl;
                // 添加过的话，在set中插入新的行号
                p->insert(line_number);
            }
            else
            {
                // 未添加过，先给指针申请空间，再插入行号
                p = make_shared<set<size_type>>();
                p->insert(line_number);
            }
            ++word_number[word];            //记录出现次数
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
    auto none = make_shared<set<size_type>>();
    if (word_number.find(s) != word_number.end())
    {
        return QueryResult(s, word_number[s], ptext, word_line[s]);
    }
    else
    {
        return QueryResult(s, 0, ptext, none);
    }
}

#endif