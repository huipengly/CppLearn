#include "Person.h"

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.name << " " << person.address;         //不要带endl，将格式控制留给用户
    return os;
}