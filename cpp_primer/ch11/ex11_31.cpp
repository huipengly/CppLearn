/**
 * @brief c++ primer 5th 练习11.31
 * 
 * @file ex11_31.cpp
 * @author huipengly
 * @date 2018-08-21
 */
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    multimap<string, string> authors;
    authors.insert({"aa", "aab1"});
    authors.insert({"bb", "bbb1"});
    authors.insert({"aa", "aab2"});
    authors.insert({"bb", "bbb2"});
    authors.insert({"bb", "bbb3"});

    for (auto a : authors)
    {
        cout << a.first << ", " << a.second << endl;
    }

    cout << "erase aa" << endl;

    auto it = authors.find("aa");
    if (it != authors.end())
    {
        cout << "erasing" << endl;
        authors.erase(it);
    }

    for (auto a : authors)
    {
        cout << a.first << ", " << a.second << endl;
    }

    cout << "erase cc" << endl;

    auto it2 = authors.find("cc");
    if (it2 != authors.end())
    {
        cout << "erasing" << endl;
        authors.erase(it);
    }

    for (auto a : authors)
    {
        cout << a.first << ", " << a.second << endl;
    }

    return 0;
}