#include "../ch14/Sales_data.h"
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Base{
public:
    // virtual void fun() = 0;
    Base() = default;
    virtual ~Base() = default;      // Hints: 这里只需要有一个虚析构函数，就能完成动态绑定。
};

class Derived : public Base {
public:
    // void fun() {}
};

ostream& translate(ostream &os, const type_info& type)
{
    if (type == typeid(int))
        os << "int";
    else if (type == typeid(int[10]))
        os << "int[10]";
    else if (type == typeid(Sales_data))
        os << "Sales_data";
    else if (type == typeid(std::string))
        os << "std::string";
    else if (type == typeid(Base*))
        os << "Base*";
    else if (type == typeid(Base))
        os << "Base";
    else if (type == typeid(Derived*))
        os << "Derived*";
    else if (type == typeid(Derived))
        os << "Derived";

    return os;
}

int main(int argc, char const *argv[])
{
    int arr[10];
    Derived d;
    Base *p = &d;

    cout << typeid(42).name() << ", "
         << typeid(arr).name() << ", "
         << typeid(Sales_data).name() << ", "
         << typeid(std::string).name() << ", "
         << typeid(p).name() << ", "
         << typeid(*p).name() << endl;          // Hints: 对应的类要有动态绑定的函数才会显示为对应类

    translate(cout, typeid(42)) << ", ";
    translate(cout, typeid(arr)) << ", ";
    translate(cout, typeid(Sales_data)) << ", ";
    translate(cout, typeid(std::string)) << ", ";
    translate(cout, typeid(p)) << ", ";
    translate(cout, typeid(*p)) << endl;          // Hints: 对应的类要有动态绑定的函数才会显示为对应类

    return 0;
}
