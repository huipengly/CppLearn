#include "Basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for (auto iter = item.begin();
              iter != item.end();
              iter = item.upper_bound(*iter))
    {
        sum += print_total(os, **iter, item.count(*iter));
    }
    std::cout << "Total sale: " << sum << std::endl;
}

void Basket::add_item(const Quote &q)
{
    // 这里不用make_shared，因为q.clone已经申请了空间
    item.insert(std::shared_ptr<Quote>(q.clone()));
}

void Basket::add_item(Quote &&q)
{
    item.insert(std::shared_ptr<Quote>(std::move(q).clone()));
}