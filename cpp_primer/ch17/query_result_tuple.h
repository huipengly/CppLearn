/**
 * @brief 查询结果类
 * 
 * @file query_result_tuple.h
 * @author huipengly
 * @date 2018-09-22
 */
#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>

typedef std::tuple<std::string, std::shared_ptr<std::set<std::vector<int>::size_type>>, std::shared_ptr<std::vector<std::string>>> QueryResult;

/**
 * @brief 根据个数，判断是否加复数
 * 
 * @param ctr 个数
 * @param word 单词
 * @param ending 单词负数词根
 * @return std::string 处理后的单词
 */
std::string makr_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

/**
 * @brief 打印QueryResult
 * 
 * @param os 输出流类的引用，例如cout
 * @param qr 需要打印的QueryResult
 * @return std::ostream& 返回输出流
 */
std::ostream& print(std::ostream &os, const QueryResult &qr)
{
    os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " " << makr_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
    for (auto num : *(std::get<1>(qr)))                               // 指针解引用之后是map<std::string, std::set<int>>
    {
        os << "\t(line " << num + 1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;     // 行从1开始，vector从0开始
    }
    return os;      // 记得返回
}

#endif