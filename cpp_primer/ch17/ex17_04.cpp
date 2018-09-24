/**
 * @brief 练习17.04
 * 
 * @file ex17_04.cpp
 * @author huipengly
 * @date 2018-09-24
 */
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include "../ch14/Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

/**
 * @brief 定义一个类型,用来记录销售了书籍的书店.第一个变量为书店序号,
 *        第二个为书在书店销售记录开始位置迭代器,第三个为结束位置后一个迭代器
 * 
 */
typedef tuple<vector<Sales_data>::size_type, 
              vector<Sales_data>::const_iterator, 
              vector<Sales_data>::const_iterator> matches;

/**
 * @brief 查找书籍在书店销售记录
 * 
 * @param book 书籍ISBN
 * @param files 各书店销售记录
 * @return vector<matches> 返回销售了书籍的书店信息
 */
vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        // auto found = equal_range(it->cbegin(), it->cend(), book,
        //                          [](const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() == rhs.isbn(); });    // 最后一个比较函数需要输入两个变量，不是一个
		auto found = equal_range(it->cbegin(), it->cend(), book,
			compareIsbn);    // 最后一个比较函数需要输入两个变量，不是一个
        if (found.first != found.second)
        {
            ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
        }
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
    string s;
    while (in >> s)
    {
        auto trans = findBook(files, s);
        if (trans.empty())
        {
            os << s << "not found in any strores" << endl;
            continue;
        }
        for (const auto &store : trans)
        {
            os << "store " << get<0>(store) << " sales: " << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<Sales_data>> files;
    vector<Sales_data> s1{{"11", 1, 1}, {"11", 1, 1}, {"22", 2, 2}};
    vector<Sales_data> s2{{"22", 1, 1}, {"22", 1, 1}, {"33", 3, 3}};
    vector<Sales_data> s3{{"22", 1, 1}, {"22", 1, 1}, {"22", 2, 2}};
    files.push_back(s1);
    files.push_back(s2);
    files.push_back(s3);
    reportResults(cin, cout, files);
    return 0;
}
