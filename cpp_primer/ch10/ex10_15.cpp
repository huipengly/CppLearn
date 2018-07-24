/**
 * @brief c++ primer 5th 练习10.15
 * 
 * @file ex10_15.cpp
 * @author huipengly
 * @date 2018-07-24
 * @note 书p349
 */
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int a = 10;
    auto f = [a](int b) -> int { return a + b; };

    cout << f(22) << endl;
    return 0;
}