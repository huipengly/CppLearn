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
    auto f = [&count] () mutable -> int {if (count == 0) {return true;} --count; return false; };
    while(true)
    {
        if (f())
        {
            cout << "count = " << count << endl;
            break;
        }
        else
        {
            cout << "count = " << count << endl;
        }
    }
    if (f())
    {
        cout << "count = " << count << endl;
    }
    return 0;
}