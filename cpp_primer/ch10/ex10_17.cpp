/**
 * @brief c++ primer 5th 练习10.17
 * 
 * @file ex10_17.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include "../ch07/Sales_data.h"
#include <algorithm>
using std::sort;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<Sales_data> item_vec{Sales_data("01"), Sales_data("04"), Sales_data("02"), Sales_data("08")};
    sort(item_vec.begin(), item_vec.end(), [](const Sales_data &item1, const Sales_data &item2) { return item1.isbn() < item2.isbn(); });

    for (const auto &item : item_vec)
    {
        print(cout, item);
        cout << endl;
    }

    return 0;
}