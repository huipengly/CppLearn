#include <vector>
#include <algorithm>
#include <functional>
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;

auto count_price(const vector<Sales_data>& Svec, double price) -> decltype(Svec.begin())
{
    // function<double ()> fcn(Sales_data::AVG); 
    // function<double () const> fcn(&Sales_data::avg_price);
    auto fcn = bind(&Sales_data::avg_price, _1);
    return find_if(Svec.begin(), Svec.end(), [&](const Sales_data& s) { return fcn(s) > price; });
    // return upper_bound(Svec.begin(), Svec.end(), price, mem_fn(&Sales_data::avg_price));
}

int main(int argc, char const *argv[])
{
    vector<Sales_data> vec = { Sales_data("978-7-121-20038-0", 12, 128.0),
                               Sales_data("978-7-121-20038-0", 10, 98.0),
                               Sales_data("978-7-121-20038-0", 12, 108.0)
                             };
    auto it = count_price(vec, 98);
    cout << *it << endl;
    return 0;
}
