#ifndef _BASKET_H_
#define _BASKET_H_
#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

class Basket
{
public:
    void add_item(const std::shared_ptr<Quote> &sale)
        { item.insert(sale); }
    void add_item(const Quote &);
    void add_item(Quote &&);
    double total_receipt(std::ostream &) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> item{compare};
};

#endif