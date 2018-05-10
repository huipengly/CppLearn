#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str, pre_str;
    bool twice_flag = false;
    cout << "Please input some words." << endl;

    while(cin >> str)
    {
        if(str == pre_str)
        {
            twice_flag = true;
            break;
        }
        pre_str = str;
    }

    if (twice_flag)
    {
        cout << str << " has appeared twice" << endl;   //错误1：str和后面的句子之间没有空格
    }
    else
    {
        cout << "No word has appeared twice" << endl;
    }

    // //错误2：这个逻辑有问题，如果说没有重复的话，最后一个str会赋值给pre_str。
    // if (str == pre_str)
    // {
    //     cout << str << " has appeared twice" << endl;   //错误1：str和后面的句子之间没有空格
    // }
    // else
    // {
    //     cout << "No word has appeared twice" << endl;
    // }

    return 0;
}