#include <iostream>
#include "Quote.h"

void Quote::debug()
{
    std::cout << "bookNo = " << bookNo << std::endl;
    std::cout << "price = " << price << std::endl;
}

double BulkQuote::net_price(size_t n) const
{
    auto one_price = n > min_qty ? price * (1 - discount) : price;
    return n * one_price;
}

void BulkQuote::debug()
{
    std::cout << "bookNo = " << isbn() << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "min_qty = " << min_qty << std::endl;
    std::cout << "discount = " << discount << std::endl;
}


double LimitQuote::net_price(size_t n) const
{
    double ret = 0;
    if (n < max_qty)
    {
        ret = n * price * (1 - discount);
    }
    else if (n >= max_qty)
    {
        ret = max_qty * price * (1 - discount) + (n - max_qty) * price;
    }
    return ret;
}

void LimitQuote::debug()
{
    std::cout << "bookNo = " << isbn() << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "max_qty = " << max_qty << std::endl;
    std::cout << "discount = " << discount << std::endl;
}
