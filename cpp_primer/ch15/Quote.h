/**
 * @brief Quote类
 * 
 * @file Quote.h
 * @author huipengly
 * @date 2018-09-06
 */
#ifndef _QUOTE_H_
#define _QUOTE_H_
#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &s, double p) : bookNo(s), price(p) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t sz) const { return price * sz; }
private:
    std::string bookNo;
protected:
    double price;
};

#endif