#include <iostream>
#include <stdexcept>
#include "Query.h"
using namespace std;

// Hints: 为了完成题目，需要将测试用的函数设置为各个类的友元
void cast_test()
{
    AndQuery a1{Query("value1"), Query("value2")};
    QueryBase &b1 = a1;
    QueryBase &b2 = a1;
    OrQuery o1{Query("value1"), Query("value2")};
    QueryBase &b3 = o1;
    if (typeid(b1) == typeid(b2))
        cout << "b1 b2 has same type." << endl;
    else
        cout << "b1 b2 has different type." << endl;

    if (typeid(b1) == typeid(b3))
        cout << "b1 b3 has same type." << endl;
    else
        cout << "b1 b3 has different type." << endl;

    if (typeid(b1) == typeid(AndQuery))
        cout << "b1 is AndQuery." << endl;
    else
        cout << "b1 is not AndQuery." << endl;

    if (typeid(b2) == typeid(AndQuery))
        cout << "b2 is AndQuery." << endl;
    else
        cout << "b2 is not AndQuery." << endl;

    if (typeid(b3) == typeid(AndQuery))
        cout << "b3 is AndQuery." << endl;
    else
        cout << "b3 is not AndQuery." << endl;
}


int main(int argc, char const *argv[])
{
    cast_test();
    return 0;
}
