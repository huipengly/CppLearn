/**
 * @brief c++ primer 5th 练习10.29
 * 
 * @file ex10_29.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <iterator>
using std::istream_iterator; using std::back_inserter;
#include <algorithm>
using std::copy;

int main()
{
    ifstream ifs("ex10_29.cpp");
    istream_iterator<string> it(ifs), eof;
    vector<string> svec;

    copy(it, eof, back_inserter(svec));

    for (const auto &str : svec)
    {
        cout << str << endl;
    }
    return 0;
}