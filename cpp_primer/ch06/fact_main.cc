#include "Chapter6.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
    int n = 0;
    cout << "Please input a number: ";
    while (cin >> n)
    {
        if (n < 0)
        {
            cout << "Please input a positive number: " << endl;
        }
        else
        {
            cout << "fact(" << n << ") = " << fact(n) << endl;
        }

        string repeat_str;
        cout << "MORE? yes or no: ";
        cin >> repeat_str;
        if (!repeat_str.empty() && toupper(repeat_str[0]) == 'N')
        {
            break;
        }
        else
        {
            cout << "Please input a number: ";
        }
    }
    return 0;
}