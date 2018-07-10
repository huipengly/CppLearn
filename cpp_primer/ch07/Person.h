#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

struct Person
{
    string name;
    string address;

    string get_name () const { return name; }
    string get_address() const { return address; }
};

istream &read(istream&, Person&);
ostream &print(ostream&, const Person&);

#endif //_PERSON_H_