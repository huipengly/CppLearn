#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

int main()
{
    string str1, str2;
    string status;          //记录是否重复输入状态
    do
    {
        cout << "Please input two strings." << endl;
        
        cin >> str1 >> str2;
        
        if (str1.size() < str2.size())
        {
            cout << "The shorter string is : " << str1 << endl;
        }
        else if (str1.size() > str2.size())
        {
            cout << "The shorter string is : " << str2 << endl;
        }
        else if (str1.size() == str2.size())
        {
            cout << "The two string have the same size!" << endl;
        }

        cout << "Do you want to input more? Enter yes or no : ";
        cin >> status;
    } while (!status.empty() && status[0] != 'n');  //错误1："status.empty"。判断空的是一个方法，要加括号。
    return 0;       //错误2：忘加分号了！！！
}
