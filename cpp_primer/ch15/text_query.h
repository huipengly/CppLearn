/**
 * @brief 文本查询类
 * 
 * @file text_query.h
 * @author huipengly
 * @date 2018-09-08
 */
#ifndef _TEXT_QUERY_H_
#define _TEXT_QUERY_H_

#include "query_result.h"
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

#endif