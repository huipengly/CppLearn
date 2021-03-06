#include "Sales_data.h"

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    if (lhs.isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", lhs.isbn(), rhs.isbn());
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data minus(lhs);
    minus -= rhs;
    return minus;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
    double price;               // 不需要初始化
    is >> item.bookNo >> item.units_sold >> price;
    if (is)                     // 检查输入是否成功
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();    // 失败赋予默认状态
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data Sales_data::operator=(const std::string &s)
{
    // bookNo = s;
    // units_sold = 0;
    // revenue = 0.0;
    *this = Sales_data(s);
    return *this;           // 记得return！
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return (lhs.bookNo == rhs.bookNo) && (lhs.revenue == rhs.revenue) && (lhs.units_sold == rhs.units_sold);
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}