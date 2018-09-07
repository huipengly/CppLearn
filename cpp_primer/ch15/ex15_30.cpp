#include "Basket.h"
#include "Quote.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    Basket basket;
    Quote q1("0-201-82470-1", 50);
    BulkQuote q2("0-201-54848-8", 60, 3, .25);
    LimitQuote q3("7-121-15535-2", 100, 1, .4);

    // 4本
    basket.add_item(q1);
    basket.add_item(q1);
    basket.add_item(q1);
    basket.add_item(q1);

    // 5本
    basket.add_item(q2);
    basket.add_item(q2);
    basket.add_item(q2);
    basket.add_item(q2);
    basket.add_item(q2);

    // 3本 
    basket.add_item(q3);
    basket.add_item(q3);
    basket.add_item(q3);

    basket.total_receipt(cout);

    return 0;
}
