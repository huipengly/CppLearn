/**
 * @brief c++ primer 5th 练习12.02
 * 
 * @file ex12_02.cpp
 * @author huipengly
 * @date 2018-08-22
 */
#include "str_blob.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "b", "c"};
        b1 = b2;
        b1.push_back("d");
        cout << "b2.back() : " << b2.back() << endl;
    }

    cout << "b1.back() : " << b1.back() << endl;
    cout << "b1.pop_back()" << endl;
    b1.pop_back();
    cout << "b1.back() : " << b1.back() << endl;
    cout << "b1.pop_back()" << endl;
    b1.pop_back();
    cout << "b1.back() : " << b1.back() << endl;
    cout << "b1.pop_back()" << endl;
    b1.pop_back();
    cout << "b1.back() : " << b1.back() << endl;
    cout << "b1.pop_back()" << endl;
    b1.pop_back();
    // 下面的会报错
    // cout << "b1.pop_back() : " << b1.back() << endl;
    // b1.pop_back();

    // 需要有重载的const的front
    const StrBlob b3 = {"e", "f"};
    cout << "b3.front() : " << b3.front() << endl;

    return 0;
}