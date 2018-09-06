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
    virtual double net_price(std::size_t sz) const { return price * sz; }
    virtual void debug();
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class DiscQuote : public Quote
{
public:
    DiscQuote() = default;
    DiscQuote(const std::string &book, double sales_price, std::size_t qty, double disc) :
        Quote(book, sales_price), quantity(qty), discount(disc) {}
    virtual double net_price(std::size_t n) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote(const std::string &book, double sales_price, std::size_t qty, double disc) :
        DiscQuote(book, sales_price, qty, disc) {}
    double net_price(std::size_t) const override;
    void debug() override;
};

class LimitQuote : public DiscQuote
{
public:
    LimitQuote(const std::string &book, double sales_price, std::size_t qty, double disc) :
        DiscQuote(book, sales_price, qty, disc) {}
    double net_price(std::size_t) const override;
    void debug() override;
};

#endif