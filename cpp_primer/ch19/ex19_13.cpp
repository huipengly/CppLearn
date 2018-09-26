#include <iostream>
#include "Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
    auto pdata = Sales_data::data();
    Sales_data s1("aaa", 1, 1), *s2 = new Sales_data("bbb", 1, 1);
    cout << s1.*pdata << endl;
    cout << s2->*pdata << endl;
    return 0;
}
