#include <iostream>
#include "Quote.h"

Quote &Quote::operator=(const Quote &rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;
    std::cout << "Quote &operator=(const Quote &)" << std::endl;
    return *this;
}

Quote &Quote::operator=(Quote &&rhs)
{
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    std::cout << "Quote &operator=(Quote &&)" << std::endl;
    return *this;
}

void Quote::debug()
{
    std::cout << "bookNo = " << bookNo << std::endl;
    std::cout << "price = " << price << std::endl;
}

DiscQuote &DiscQuote::operator=(const DiscQuote &rhs)
{
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    std::cout << "DiscQuote &operator=(const DiscQuote &)" << std::endl;
    return *this;
}

DiscQuote &DiscQuote::operator=(DiscQuote &&rhs)
{
    Quote::operator=(std::move(rhs));
    quantity = std::move(rhs.quantity);
    discount = std::move(rhs.discount);
    std::cout << "DiscQuote &operator=(DiscQuote &&)" << std::endl;
    return *this;
}

BulkQuote &BulkQuote::operator=(const BulkQuote &rhs)
{
    DiscQuote::operator=(rhs);
    std::cout << "BulkQuote &operator=(const BulkQuote &)" << std::endl;
    return *this;
}

BulkQuote &BulkQuote::operator=(BulkQuote &&rhs)
{
    DiscQuote::operator=(std::move(rhs));
    std::cout << "BulkQuote &operator=(BulkQuote &&)" << std::endl;
    return *this;
}

double BulkQuote::net_price(size_t n) const
{
    auto one_price = n > quantity ? price * (1 - discount) : price;
    return n * one_price;
}

void BulkQuote::debug()
{
    std::cout << "bookNo = " << isbn() << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "min_qty = " << quantity << std::endl;
    std::cout << "discount = " << discount << std::endl;
}

LimitQuote &LimitQuote::operator=(const LimitQuote &rhs)
{
    DiscQuote::operator=(rhs);
    std::cout << "LimitQuote &operator=(const LimitQuote &)" << std::endl;
    return *this;
}

LimitQuote &LimitQuote::operator=(LimitQuote &&rhs)
{
    DiscQuote::operator=(std::move(rhs));
    std::cout << "LimitQuote &operator=(LimitQuote &&)" << std::endl;
    return *this;
}

double LimitQuote::net_price(size_t n) const
{
    double ret = 0;
    if (n < quantity)
    {
        ret = n * price * (1 - discount);
    }
    else if (n >= quantity)
    {
        ret = quantity * price * (1 - discount) + (n - quantity) * price;
    }
    return ret;
}

void LimitQuote::debug()
{
    std::cout << "bookNo = " << isbn() << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "max_qty = " << quantity << std::endl;
    std::cout << "discount = " << discount << std::endl;
}
