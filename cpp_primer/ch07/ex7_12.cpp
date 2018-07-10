#include "Person.h"
#include <iostream>
using std::cin; using std::cout;

int main()
{
    Person person;

    read(cin, person);
    print(cout, person);

    return 0;
}