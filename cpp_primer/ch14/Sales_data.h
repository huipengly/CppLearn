#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_

#include <string>
#include <iostream>

class Sales_data;                                      //先声明这个类名，给下面三个声明使用。
std::istream & operator>>(std::istream&, Sales_data&);           //read的声明要在类定义前，不然无法调用
std::ostream & operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);

// template <class> class std::hash;

class Sales_data
{
    friend std::istream & operator>>(std::istream&, Sales_data&);
    friend std::ostream & operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
    friend struct std::hash<Sales_data>;
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);
public:
    Sales_data(const std::string &s, const unsigned &n, const double &p) : 
                bookNo(s), units_sold(n), revenue(p * n) { /*std::cout << "Sales_data(const std::string &s, const unsigned &n, const double &p)\n";*/ }
    Sales_data() : Sales_data("", 0, 0) { /*std::cout << "Sales_data()\n";*/ }
    Sales_data(const std::string& s) : Sales_data(s, 0, 0) { /*std::cout << "Sales_data(const std::string& s)\n";*/ }
    Sales_data(std::istream& is) : Sales_data() { /*std::cout << "Sales_data(std::istream& is)\n"; is >> *this;*/ }

    std::string isbn() const { return bookNo; }
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    Sales_data operator=(const std::string&);

    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return revenue; }

private:
    double avg_price() const { return revenue / units_sold; }

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


namespace std{
    template<>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator()(const Sales_data &s) const
        {
            return hash<std::string>()(s.bookNo) ^
                    hash<unsigned>()(s.units_sold) ^
                    hash<double>()(s.revenue);
        }
    };
}

#endif