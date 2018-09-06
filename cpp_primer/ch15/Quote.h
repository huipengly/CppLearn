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
    double price = 0.0;
};

class BulkQuote : public Quote
{
public:
    BulkQuote(const std::string &book, double sales_price, size_t qty, double disc) :
        Quote(book, sales_price), min_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class LimitQuote : public Quote
{
public:
    LimitQuote(const std::string &book, double sales_price, size_t qty, double disc) :
        Quote(book, sales_price), max_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
private:
    size_t max_qty = 0;             //!< ??????
    double discount = 0.0;
};

#endif