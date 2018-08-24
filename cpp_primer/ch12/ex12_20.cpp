/**
 * @brief 练习12.20
 * 
 * @file ex12_20.cpp
 * @author huipengly
 * @date 2018-08-24
 */
#include "ex12_19.h"
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    ifstream input("ex12_20.cpp");
    string text;
    StrBlob sb;
    while (getline(input, text))
    {
        sb.push_back(text);
    }

    StrBlobPtr psb = sb.begin();
    
    // while (psb != sb.end())
    // {
    //     cout << psb.deref() << endl;
    //     psb.incr();
    // }

    for (StrBlobPtr psb = sb.begin(); psb != sb.end(); psb.incr())
    {
        cout << psb.deref() << endl;
    }

    return 0;
}