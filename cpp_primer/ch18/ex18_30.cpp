#include <iostream>
using std::cin; using std::cout; using std::endl;

class Class {
public:
	Class() { cout << "Class() called" << endl; }
	~Class() { cout << "~Class() called" << endl; }
};

class Base : public Class
{
public:
    Base() { cout << "Base()" << endl; }
    Base(const Base&) : Base() { cout << "Base(const Base&)"; };
    Base(const int&) { cout << "Base(const int&)" << endl; }
	~Base() { cout << "~Base() called" << endl; }
};

class D1 : virtual public Base {
public:
	D1() : Base() { cout << "D1() called" << endl; }
    D1(const D1&) : Base()
	~D1() { cout << "~D1() called" << endl; }
};

class D2 : virtual public Base {
public:
	D2() { cout << "D2() called" << endl; }
	~D2() { cout << "~D2() called" << endl; }
};

class MI : public D1, public D2 {
public:
	MI() { cout << "MI() called" << endl; }
	~MI() { cout << "~MI() called" << endl; }
};

class Final : public MI, public Class {
public:
	Final() { cout << "Final() called" << endl; }
	~Final() { cout << "~Final() called" << endl; }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
