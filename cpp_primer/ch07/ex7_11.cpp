#include "Sales_data.h"
#include "iostream"
using std::cin; using std::cout; using std::endl;

int main()
{
    Sales_data item1;
    Sales_data item2(cin);
    Sales_data item3("book1");
    Sales_data item4("book2", 5, 10);

    cout << "item1 : ";
    print(cout, item1);
    cout << "\nitem2 : ";
    print(cout, item2);
    cout << "\nitem3 : ";
    print(cout, item3);
    cout << "\nitem4 : ";
    print(cout, item4);
    cout << endl;

    return 0;
}