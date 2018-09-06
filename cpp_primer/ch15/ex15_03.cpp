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
    Quote q("1234", 20);
    print_total(cout, q, 2);
    return 0;
}