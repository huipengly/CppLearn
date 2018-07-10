#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

struct Person;
istream &read(istream&, Person&);
ostream &print(ostream&, const Person&);

struct Person
{
    Person() = default;
    Person(istream &is) { read(is, *this); }
    Person(const string &name, const string &address) :
            name(name), address(address) { }

    string name;
    string address;

    string get_name () const { return name; }
    string get_address() const { return address; }
};

#endif //_PERSON_H_