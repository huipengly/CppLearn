#include "Quote.h"

double BulkQuote::net_price(size_t n) const
{
    auto one_price = n > min_qty ? price * (1 - discount) : price;
    return n * one_price;
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