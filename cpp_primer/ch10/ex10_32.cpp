
/**
 * @brief c++ primer 5th 练习10.3
 * 
 * @file ex10_32.cpp
 * @author huipengly
 * @date 2018-07-25
 */
#include "../ch01/Sales_item.h"
#include <vector>
using std::vector;
#include <algorithm>
using std::sort; using std::find_if;
#include <numeric>
using std::accumulate;
#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iterator>
using std::istream_iterator;

/**
 * @brief 比较两本书销售数据isbn的大小
 * 
 * @param item1 第一本书
 * @param item2 第二本书
 * @return true 第一本书isbn比第二本大
 * @return false 第一本书isbn比第二本小或相等
 */
bool compare_isbn(const Sales_item &item1, const Sales_item &item2)
{
    return item1.isbn() < item2.isbn();
}

int main()
{
    vector<Sales_item> transaction;             // !<交易记录
    istream_iterator<Sales_item> it(cin), eof;

    // 读取每一条记录
    while (it != eof)
    {
        transaction.push_back(*it++);
    }

    // 排序记录
    sort(transaction.begin(), transaction.end(), compare_isbn);

    for (auto beg = transaction.cbegin(), end = beg; beg != transaction.cend(); beg = end)
    {
        // 查找相同记录
        end = find_if(beg, transaction.cend(), [beg](const Sales_item &item) {return beg->isbn() != item.isbn(); });
        // 合并输出
        auto sum = accumulate(beg, end, Sales_item(beg->isbn()));
        cout << sum << endl;

    }

    return 0;
}