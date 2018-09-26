/**
 * @brief 查询结果类
 * 
 * @file query_result.h
 * @author huipengly
 * @date 2018-09-08
 */
#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);

/**
 * @brief 存储查询结果
 * 
 */
class QueryResult
{
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    typedef std::vector<int>::size_type line_no;
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

std::ostream& print(std::ostream &os, const QueryResult &qr);

#endif