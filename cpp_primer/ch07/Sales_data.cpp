#include "Sales_data.h"

using std::endl;

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

double Sales_data::avg_price() const
{
    return revenue / units_sold;
}

Sales_data add(const Sales_data &A, const Sales_data &B)
{
    Sales_data Sales_data_sum;

if (A.isbn() == B.isbn())
{
    Sales_data_sum.bookNo = A.isbn();
    Sales_data_sum.units_sold = A.units_sold + B.units_sold;
    Sales_data_sum.revenue = A.units_sold + B.units_sold;
}

return Sales_data_sum;
}

istream &read(istream &is, Sales_data &sales_data)
{
    double price = 0;
    is >> sales_data.bookNo >> sales_data.units_sold >> price;
    sales_data.revenue = sales_data.units_sold * price;
    return is;
}

ostream &print(ostream &os, Sales_data &sales_data)
{
    os << sales_data.bookNo << " " << sales_data.units_sold << " " << sales_data.revenue;

    if (sales_data.units_sold != 0)
    {
        os << " " << sales_data.revenue / sales_data.units_sold << endl;
    }
    else
    {
        os << "(no sales)" << endl;
    }
    return os;
}