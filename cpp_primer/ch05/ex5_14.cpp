#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    string pre_str;
    string max_str;
    int counter = 0;
    int max_counter = 0;
    while (cin >> str)
    {
        if (str == pre_str)
        {
            ++counter;
        }
        else
        {
            if(counter > max_counter)
            {
                max_str = pre_str;
                max_counter = counter + 1;//当第一次有相等时，说明已经和前一个像等了，所以总数应该加一个
            }
            counter = 0;
        }
        pre_str = str;
    }
    if(max_counter != 0)
    {
        cout << max_str << " : " << max_counter << endl;
    }
    else
    {
        cout << "There's no duplicated string." << endl;
    }
    return 0;
}