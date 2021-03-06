#include <memory>
#include <vector>
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

    vector<Quote> qvec{q, bq, lq};
    vector<shared_ptr<Quote>> qpvec{make_shared<Quote>(q), make_shared<BulkQuote>(bq), make_shared<LimitQuote>(lq)};

    print_total(cout, qvec[0], 2);
    print_total(cout, qvec[1], 4);
    print_total(cout, qvec[2], 2);
    print_total(cout, *qpvec[0], 2);
    print_total(cout, *qpvec[1], 4);
    print_total(cout, *qpvec[2], 2);
    return 0;
}