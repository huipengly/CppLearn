/**
 * @brief c++ primer 5th 练习10.42
 * 
 * @file ex10_42.cpp
 * @author huipengly
 * @date 2018-07-25
 */
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
    list<string> slst = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};

    slst.sort();
    slst.unique();

    for (auto &str : slst)
    {
        cout << str << endl;
    }
    return 0;
}