#include "Query.h"
#include <iostream>
using std::ostream;
#include <memory>
using std::make_shared;
#include <algorithm>
using std::set_intersection;
#include <iterator>
using std::inserter;
#include <set>
using std::set;

/**
 * @brief 输出query的内容
 * 
 */
ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    // auto include_query_result = text.query(query.eval());
    auto result = query.eval(text);                   // Hints:QueryResult 获取要排除的词的QueryResult
                                                    // Hints:这里不应该调用自身的eval
    // set<line_no> not_include_line{};
    auto ret_lines = make_shared<set<line_no>>();   // 建立一个需要返回的排除行，因为QueryResult的构造函数使用指针，所以这里使用指针传参，而非对象
    // auto beg = include_query_result.begin(), end = include_query_result.end();
    auto beg = result.begin(), end = result.end();  // 只是变量名不同
    auto sz = result.get_file()->size();            // 获取文件有多少行，这个第一遍写忘记了。
    for (auto n = 0; n != sz; ++n)
    {
        if (beg == end | *beg == sz)
        {
            ret_lines->insert(n);
        }
        else if (beg != end)                        // *beg和n相等的时候要将迭代器移动向下一个
        {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}
