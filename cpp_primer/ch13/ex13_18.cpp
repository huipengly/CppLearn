/**
 * @brief 练习13.18
 * 
 * @file ex13_18.cpp
 * @author huipengly
 * @date 2018-09-02
 */

#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <string>
using std::string;

class Employee
{
public: 
    friend ostream& print(ostream&, const Employee&);
    Employee(const string &str) : name(str), number(com_num) { ++com_num; }
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
private:
    static int com_num;
    string name;
    int number;
};

ostream& print(ostream& os, const Employee& em)
{
    os << em.name + " " << em.number;
    return os;
}

int Employee::com_num = 0;

int main(int argc, char const *argv[])
{
    Employee e1("jobs"), e2("bill");
    print(cout, e1) << endl;
    print(cout, e2) << endl;
    // e1 = e2; // 错误
    // Employee e3 = e1; // 错误
    return 0;
}
