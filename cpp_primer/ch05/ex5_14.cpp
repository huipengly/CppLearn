#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    string pre_str;
    int counter = 1;
    while (cin >> str)
    {
        if (str == pre_str)//当第一次有相等时，说明已经有一个了，加完之后应该是2个
        {
            ++counter;
        }
        else
        {
            if (counter != 1)
            {
                cout << pre_str << " : " << counter << endl;
            }
            counter = 1;
        }
        pre_str = str;
    }
    if(counter != 1)//最后如果有连续的话，while不会处理，这里处理
    {
        cout << pre_str << " : " << counter << endl;
    }
    return 0;
}