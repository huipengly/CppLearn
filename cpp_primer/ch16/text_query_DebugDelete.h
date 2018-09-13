/**
 * @brief 文本查询类，使用自己实现的删除器
 * 
 * @file text_query_DebugDelete.h
 * @author huipengly
 * @date 2018-09-13
 */
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include "query_result_DebugDelete.h"
#include "DebugDelete.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>

/**
 * @brief 文本查询
 * 
 */
class TextQuery
{
public:
    typedef std::vector<int>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;                         //!< 存储文本，一行为一个string
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;           //!< 存储单词，和单词所在的列
};


/**
 * @brief Construct a new Text Query:: Text Query object
 * 
 * @param is 输入文件流
 * @note 根据文件流，存储文本，统计单词出现次数，出现行号
 */
TextQuery::TextQuery(std::ifstream &is): 
        file(new std::vector<std::string>(), DebugDelete())
{
    std::string text;
    // 按行读取文件流
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;               // 记录当前读取行号
        std::istringstream line(text);
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)     // 第一次遇到这个单词时，此指针为空
            {
                lines.reset(new std::set<line_no>);  // 分配一个新的set
            }
            lines->insert(n);                   // 将此行号插入
        }
    }
}

/**
 * @brief 查询单词
 * 
 * @param sought 单词
 * @return QueryResult 查询结果
 */
QueryResult TextQuery::query(const std::string& sought) const       // Hints:这里要加const，因为可能使静态对象调用
{
    static std::shared_ptr<std::set<line_no>> nodata(std::make_shared<std::set<line_no>>());     // 定义成静态的，这种nodata只需要一个
    auto loc = wm.find(sought);                            // Hints:这里需要单独将迭代器定义出来，不然下面word_number[sought]将报错，因为这个操作可能在set里添加东西，不满足const的要求
    if (loc != wm.end())
    {
        return QueryResult(sought, loc->second, file);
    }
    else
    {
        return QueryResult(sought, nodata, file);
    }
}

#endif