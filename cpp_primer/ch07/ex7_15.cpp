#include "Person.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    Person p1;
    Person p2(cin);
    Person p3("huipeng", "liaoning");

    cout << "p1 : ";
    print(cout, p1);
    cout << "\np2 : ";
    print(cout, p2);
    cout << "\np3 : ";
    print(cout, p3);
    cout << endl;

    return 0;
}