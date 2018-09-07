#include "Quote.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Quote q("978-7-121-15535-2", 20);
    BulkQuote bq("978-7-121-15535-2", 20, 3, 0.2);
    LimitQuote lq("978-7-121-15535-2", 20, 2, 0.1);

    BulkQuote bq1(bq);              // Q-D-B
    LimitQuote lq1(lq);             // Q-D-L
    BulkQuote bq2(std::move(bq));   // Q-D-B
    LimitQuote lq2(std::move(lq));  // Q-D-L
    bq1 = bq2;                       // Q-D-B
    lq1 = lq2;                       // Q-D-L
    return 0;
}
