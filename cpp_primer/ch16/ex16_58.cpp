#include <iostream>
#include "../ch13/StrVec.h"
using namespace std;

int main()
{
    StrVec sv{"0", "1", "2", "3"};
    sv.emplace_back(10, 'c');
    sv.emplace_back(string("hello"));
    for (auto s : sv)
    {
        cout << s << endl;
    }
}