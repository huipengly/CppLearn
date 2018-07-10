#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

class Person;
istream &read(istream&, Person&);
ostream &print(ostream&, const Person&);

class Person
{
friend istream &read(istream&, Person&);
friend ostream &print(ostream&, const Person&);
public:
    Person() = default;
    Person(istream &is) { read(is, *this); }
    Person(const string &name, const string &address) :
            name(name), address(address) { }

    string get_name () const { return name; }
    string get_address() const { return address; }

private:
    string name;
    string address;
};

#endif //_PERSON_H_