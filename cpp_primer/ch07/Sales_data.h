#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

class Sales_data;                                      //先声明这个类名，给下面三个声明使用。
istream &read(istream&, Sales_data&);                   //read的声明要在类定义前，不然无法调用
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

class Sales_data
{
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend Sales_data add(const Sales_data&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(istream& is) { read(is, *this); }
    Sales_data(const string &s, const unsigned &n, const double &p) : 
                bookNo(s), units_sold(n), revenue(p * n) { }
    Sales_data(const string& s) : bookNo(s) { }

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const { return revenue / units_sold; }

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


#endif