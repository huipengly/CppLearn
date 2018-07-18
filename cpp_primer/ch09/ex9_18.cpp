#include <string>
using std::string;
#include <deque>
using std::deque;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    string s;
    deque<string> sdeq;
    while (cin >> s)
    {
        sdeq.push_back(s);
    }

    for (auto it = sdeq.begin(); it != sdeq.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}