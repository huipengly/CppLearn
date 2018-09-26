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

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);

/**
 * @brief 文本查询
 * 
 */
class TextQuery
{
public:
    class QueryResult;
    typedef std::vector<int>::size_type line_no;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;                         //!< 存储文本，一行为一个string
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;           //!< 存储单词，和单词所在的列
};

class TextQuery::QueryResult
{
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    // typedef std::vector<int>::size_type line_no;
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) {}
    std::set<line_no>::iterator begin() { return lines->begin(); }      //!< @brief 返回单词所在行set的第一个元素迭代器
    std::set<line_no>::iterator end() { return lines->end(); }          //!< @brief 返回单词所在行set的尾后迭代器
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }             //!< @brief 返回文本文件的指针
    
private:
    std::string sought;                                                 //!< 查询的单词
    std::shared_ptr<std::vector<std::string>> file;                     //!< 存储文本，一行为一个string
    std::shared_ptr<std::set<line_no>> lines;                           //!< 存储单词所在的列
};

std::ostream& print(std::ostream &os, const TextQuery::QueryResult &qr);

#endif