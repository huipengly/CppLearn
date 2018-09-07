/**
 * @brief Quote类
 * 
 * @file Quote.h
 * @author huipengly
 * @date 2018-09-07
 */
#ifndef _QUOTE_H_
#define _QUOTE_H_
#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &s, double p) : bookNo(s), price(p) {}
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
        { std::cout << "Quote(const Quote &q)" << std::endl;}
    Quote(Quote &&q) : bookNo(std::move(q.bookNo)), price(std::move(q.price))
        { std::cout << "Quote(Quote &&q)" << std::endl;}
    Quote &operator=(const Quote &);
    Quote &operator=(Quote &&);
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t sz) const { return price * sz; }
    virtual void debug();
    virtual ~Quote() = default;
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
    DiscQuote(const DiscQuote &d) : Quote(d), quantity(d.quantity), discount(d.discount)
        { std::cout << "DiscQuote(const DiscQuote &d)" << std::endl;}
    DiscQuote(DiscQuote &&d) : Quote(std::move(d)), quantity(std::move(d.quantity)), discount(std::move(d.discount))
        { std::cout << "DiscQuote(DiscQuote &&d)" << std::endl;}
    DiscQuote &operator=(const DiscQuote &);  // 因为纯虚类，所以不能实例对象，返回值不能为右值，必须为引用
    DiscQuote &operator=(DiscQuote &&);
    virtual double net_price(std::size_t n) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class BulkQuote : public DiscQuote
{
public:
    using DiscQuote::DiscQuote;
    BulkQuote() = default;

    // changed the below to the inherited constructor for ex15.27.
    // rules:  1. only inherit from the direct base class.
    //         2. default, copy and move constructors can not inherit.
    //         3. any data members of its own are default initialized.
    //         4. the rest details are in the section section 15.7.4.

    // BulkQuote(const std::string &book, double sales_price, std::size_t qty, double disc) :
    //     DiscQuote(book, sales_price, qty, disc) {}
    BulkQuote(const BulkQuote &b) : DiscQuote(b) 
        { std::cout << "BulkQuote(const BulkQuote &b)" << std::endl;}
    BulkQuote(BulkQuote &&b) : DiscQuote(std::move(b)) 
        { std::cout << "BulkQuote(BulkQuote &&b)" << std::endl;}
    BulkQuote &operator=(const BulkQuote &);
    BulkQuote &operator=(BulkQuote &&);
    double net_price(std::size_t) const override;
    void debug() override;
};

class LimitQuote : public DiscQuote
{
public:
    using DiscQuote::DiscQuote;
    LimitQuote() = default;
    // LimitQuote(const std::string &book, double sales_price, std::size_t qty, double disc) :
    //     DiscQuote(book, sales_price, qty, disc) {}
    LimitQuote(const LimitQuote &l) : DiscQuote(l) 
        { std::cout << "LimitQuote(const LimitQuote &l)" << std::endl;}
    LimitQuote(LimitQuote &&l) : DiscQuote(std::move(l)) 
        { std::cout << "LimitQuote(LimitQuote &&l)" << std::endl;}
    LimitQuote &operator=(const LimitQuote &);
    LimitQuote &operator=(LimitQuote &&);
    double net_price(std::size_t) const override;
    void debug() override;
};

#endif