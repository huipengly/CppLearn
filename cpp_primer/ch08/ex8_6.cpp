#include "../ch07/Sales_data.h"
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    Sales_data total;
    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}