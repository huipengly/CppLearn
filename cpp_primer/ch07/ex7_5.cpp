#include "Person.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
    Person p1;

    p1.name = "bill";
    p1.address = "The xx streeet";

    const Person p2 = p1;

    cout << p1.get_address() << " " << p1.get_name() << endl;
    cout << p2.get_address() << " " << p2.get_name() << endl;

    return 0;
}