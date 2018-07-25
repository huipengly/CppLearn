/**
 * @brief c++ primer 5th 10.34和10.35
 * 
 * @file ex10_34_35.cpp
 * @author huipengly
 * @date 2018-07-25
 */
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> ivec{0, 1, 2, 3, 4, 56, 7};

    cout << "using reverse iterator" << endl;
    for (auto r_it = ivec.crbegin(); r_it != ivec.crend(); ++r_it)
    {
        cout << *r_it << endl;
    }

    cout << "using normal iterator" << endl;
    for (auto it = ivec.cend() - 1; it != ivec.cbegin() - 1; --it)
    {
        cout << *it << endl;
    }

    return 0;
}