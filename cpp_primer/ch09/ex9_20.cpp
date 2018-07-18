#include <list>
using std::list;
#include <deque>
using std::deque;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    list<int> ilist{1, 2, 3, 3, 4, 5, 6, 7, 8, 8, 9};

    deque<int> even_deque, odd_deque;

    for (auto &i : ilist)
    {
        if (i & 0x1)
        {
            even_deque.push_back(i);
        }
        else
        {
            odd_deque.push_back(i);
        }
    }

    cout << "even number" << endl;
    for (auto &i : even_deque)
    {
        cout << i << endl;
    }

    cout << "odd number" << endl;
    for (auto &i : odd_deque)
    {
        cout << i << endl;
    }
    return 0;
}
