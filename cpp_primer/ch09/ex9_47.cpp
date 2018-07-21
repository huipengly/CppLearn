#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

void find_each_number_and_letter_use_find_first_of(const string &s)
{
    string::size_type pos = 0;
    cout << "find each number" << endl;
    while (pos != s.size())
    {
        pos = s.find_first_of("0123456789", pos);
        if (pos != string::npos)
        {
            cout << s[pos] << endl;
            ++pos;
        }
        else
        {
            break;
        }
    }

    pos = 0;
    cout << "find each letter" << endl;
    while (pos != s.size())
    {
        pos = s.find_first_of("abcdedfhigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ", pos);
        if (pos != string::npos)            // 需要判断是否未找到匹配值，不然会内存溢出
        {
            cout << s[pos] << endl;
            ++pos;
        }
        else
        {
            break;                          // 当未找到时需要破掉循环，不然会卡死
        }
    }
}

void find_each_number_and_letter_use_find_first_not_of(const string &s)
{
    string::size_type pos = 0;
    cout << "find each number" << endl;
    while (pos != s.size())
    {
        pos = s.find_first_not_of("abcdedfhigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ", pos);
        if (pos != string::npos)
        {
            cout << s[pos] << endl;
            ++pos;
        }
        else
        {
            break;
        }
    }

    pos = 0;
    cout << "find each letter" << endl;
    while (pos != s.size())
    {
        pos = s.find_first_not_of("0123456789", pos);
        if (pos != string::npos)            // 需要判断是否未找到匹配值，不然会内存溢出
        {
            cout << s[pos] << endl;
            ++pos;
        }
        else
        {
            break;                          // 当未找到时需要破掉循环，不然会卡死
        }
    }
}

int main()
{
    string str = "ab2c3d7R4E6";
    cout << "use find first of" << endl;
    find_each_number_and_letter_use_find_first_of(str);
    cout << "use find first not of" << endl;
    find_each_number_and_letter_use_find_first_not_of(str);
    return 0;
}