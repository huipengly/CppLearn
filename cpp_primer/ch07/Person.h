#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;

struct Person
{
    string name;
    string address;

    string get_name () const { return name; }
    string get_address() const { return address; }
};

#endif //_PERSON_H_