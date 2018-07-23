/**
 * @brief c++ primer 5th 练习10.12
 * 
 * @file ex10_12.cpp
 * @author huipengly
 * @date 2018-07-23
 * @note 排序Sales_data的vector
 */
#include "../ch07/Sales_data.h"
#include <algorithm>
using std::sort;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

/**
 * @brief 比较两本书销售数据isbn的大小
 * 
 * @param item1 第一本书
 * @param item2 第二本书
 * @return true 第一本书isbn比第二本大
 * @return false 第一本书isbn比第二本小或相等
 */
bool compare_isbn(const Sales_data &item1, const Sales_data &item2)
{
    return item1.isbn() < item2.isbn();
}

int main()
{
    vector<Sales_data> item_vec{Sales_data("01"), Sales_data("04"), Sales_data("02"), Sales_data("08")};
    sort(item_vec.begin(), item_vec.end(), compare_isbn);

    for (const auto &item : item_vec)
    {
        print(cout, item);
        cout << endl;
    }

    return 0;
}