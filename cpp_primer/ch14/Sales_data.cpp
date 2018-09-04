#include "Sales_data.h"

using std::endl;

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

istream &operator>>(istream &is, Sales_data &item)
{
    double price;               // 不需要初始化
    is >> item.bookNo >> item.units_sold >> price;
    if (is)                     // 检查输入是否成功
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();    // 失败赋予默认状态
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}