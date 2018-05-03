#include "Sales_item.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_item total;
    if (cin >> total)
    {
        Sales_item trans;
        while (cin >> trans)
        {
            if(total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;          //输出最后一本书信息
    }
    return 0;
}