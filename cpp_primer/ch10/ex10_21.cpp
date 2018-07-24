/**
 * @brief c++ primer 5th 练习10.21
 * 
 * @file ex10_21.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int count = 10;
    auto f = [count] () mutable -> int {if (count == 0) {return true;} --count; return false; };
    while(true)
    {
        if (f())
        {
            cout << "zero" << endl;
            break;
        }
        else
        {
            cout << "not zero" << endl;
        }
    }
    if (f())
    {
        cout << "zero" << endl;
    }
    return 0;
}