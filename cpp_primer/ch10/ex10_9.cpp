/**
 * @brief c++ primer 5th 练习10.9
 * 
 * @file ex10_9.cpp
 * @author huipengly
 * @date 2018-07-23
 */
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::unique;

int main()
{
    vector<string> svec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    sort(svec.begin(), svec.end());
    auto end_unique = unique(svec.begin(), svec.end());
    svec.erase(end_unique, svec.end());
    for (auto str : svec)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}