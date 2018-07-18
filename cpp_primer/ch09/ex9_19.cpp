#include <string>
using std::string;
#include <list>
using std::list;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    string s;
    list<string> slist;
    while (cin >> s)
    {
        slist.push_back(s);
    }

    for (auto it = slist.begin(); it != slist.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}