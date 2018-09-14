#include <iostream>
#include <unordered_set>
#include "../ch14/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data s1, s2("aaa"), s3("bbb");
    cout << hash<Sales_data>()(s1) << endl;
    unordered_multiset<Sales_data> SDset;
    SDset.insert(s1);
    SDset.insert(s2);
    SDset.insert(s1);
    SDset.insert(s3);
    for (auto sd : SDset)
    {
        cout << sd << endl;
    }
    return 0;
}
