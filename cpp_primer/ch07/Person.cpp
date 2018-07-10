#include "Person.h"

#include <iostream>
using std::endl;

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.name << " " << person.address << endl;
    return os;
}