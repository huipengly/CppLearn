#include "Sales_data.h"
#include <iostream>
using namespace std;

void test_point_to_avg()
{
    Sales_data s("aaa", 1, 1);
    Sales_data::AVG avg = &Sales_data::avg_price;   // Hints: 这里AVG是Sales_data的成员，需要在前面加上定义域说明
                                                    // Hints: 这个avg_price应该写名字，而不是avg_prive()这种调用形式
    cout << (s.*avg)() << endl; // Hints: s.*avg()是错的，s.*avg是错的
}

int main(int argc, char const *argv[])
{
    test_point_to_avg();
    return 0;
}
