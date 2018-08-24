/**
 * @brief 练习12.23
 * 
 * @file ex12_23.cpp
 * @author huipengly
 * @date 2018-08-24
 */
#include <string>
using std::string;
#include <iterator>
using std::begin; using std::end;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    char str1[] = {"hello"}, str2[] = {" world!"};
    string str3("world!"), str4(" hello");

    int str1_size = sizeof(str1) / sizeof(*str1), str2_size = sizeof(str2) / sizeof(*str2);
    char *pstr12 = new char[str1_size + str2_size - 1]();

    for (int i = 0; i != str1_size - 1; ++i)
    {
        pstr12[i] = str1[i];
    }

    for (int i = 0; i != str2_size; ++i)
    {
        pstr12[str1_size - 1 + i] = str2[i];
    }

    cout << pstr12 << endl;

    // string可以直接用+连接
    char *pstr34 = new char[str3.size() + str4.size()]();

    for (int i = 0; i != str3.size(); ++i)
    {
        pstr34[i] = str3[i];
    }

    for (int i = 0; i != str4.size(); ++i)
    {
        pstr34[str3.size() + i] = str4[i];
    }

    cout << pstr34 << endl;

    // 记得删除
    delete [] pstr12;
    delete [] pstr34;

    return 0;
}