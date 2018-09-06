#include "Quote.h"
#include <iostream>
using namespace std;

double print_total(ostream &os, Quote &item, size_t n)
{
    auto ret = item.net_price(n);
    cout << "ISBN: " <<item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote q("978-7-121-15535-2", 20);
    BulkQuote bq("978-7-121-15535-2", 20, 3, 0.2);
    LimitQuote lq("978-7-121-15535-2", 20, 2, 0.1);
    print_total(cout, q, 2);
    print_total(cout, bq, 2);
    print_total(cout, bq, 4);
    print_total(cout, lq, 1);
    print_total(cout, lq, 4);
    q.debug();
    bq.debug();
    lq.debug();
    return 0;
}