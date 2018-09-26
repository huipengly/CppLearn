#include "Sales_data.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    using AVG = double (Sales_data::*)() const;     // 这里不知道typedef怎么写
    Sales_data s("aaa", 1, 1);
    AVG avg = &Sales_data::avg_price();
    cout << avg() << endl;
    return 0;
}
