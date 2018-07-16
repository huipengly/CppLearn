#include "../ch07/Sales_data.h"
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream; using std::ofstream;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    ofstream out(argv[2]);
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
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}