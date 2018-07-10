#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

struct Sales_data
{
    Sales_data() = default;
    Sales_data(istream&);
    Sales_data(const string &s, const unsigned &n, const double &p) : 
                bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(const string& s) : bookNo(s) { }

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
istream &read(istream&, Sales_data&);
ostream &print(ostream&, const Sales_data&);

#endif