/**
 * @brief c++ primer 5th 练习11.38 重写练习11.03
 * 
 * @file ex11_38.cpp
 * @author huipengly
 * @date 2018-08-22
 */
#include <unordered_map>
using std::unordered_map;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    unordered_map<string, int> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }

    for (auto &w : word_count)
    {
        cout << w.first << " : " << w.second << endl;
    }
    return 0;
}