/**
 * @brief c++ primer 5th 练习10.14
 * 
 * @file ex10_14.cpp
 * @author huipengly
 * @date 2018-07-24
 * @note 编写一个lambda，接受两个int，返回他们的和
 */
#include <iostream>
using std::cout; using std::endl;

int main()
{
    auto f = [](int a, int b) { return a + b; };
    cout << f(1, 2) << endl;
}