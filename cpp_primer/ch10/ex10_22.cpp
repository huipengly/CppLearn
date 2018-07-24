/**
 * @brief c++ primer 5th 练习10.22
 * 
 * @file ex10_22.cpp
 * @author huipengly
 * @date 2018-07-24
 */
#include <algorithm>
using std::count_if;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <functional>
using std::placeholders::_1; using std::bind;

bool smaller_than_size(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}

int check_size(const vector<string> &words, string::size_type sz)
{
    return count_if(words.begin(), words.end(), bind(smaller_than_size, _1, sz));
}

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    cout << check_size(svec, 6) << endl;
    return 0;
}