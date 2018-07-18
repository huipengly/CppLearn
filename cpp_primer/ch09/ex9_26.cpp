#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;
#include <iterator>
using std::begin; using std::end;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 4, 8, 13, 21, 55, 89};
    vector<int> ivec(begin(ia), end(ia));
    list<int> ilist(begin(ia), end(ia));

    auto it_ivec = ivec.begin();
    while (it_ivec != ivec.end())
    {
        if (!*it_ivec & 0x1)
        {
            it_ivec = ivec.erase(it_ivec);
        }
        else
        {
            ++it_ivec;
        }
    }

    auto it_ilist = ilist.begin();
    while (it_ilist != ilist.end())
    {
        if (*it_ilist & 0x1)
        {
            it_ilist = ilist.erase(it_ilist);
        }
        else
        {
            ++it_ilist;
        }
    }

    cout << "vector erase even" << endl;
    for (auto &i : ivec)
    {
        cout << i << endl;
    }

    cout << "list erase odd" << endl;
    for (auto &i : ilist)
    {
        cout << i << endl;
    }

    return 0;
}