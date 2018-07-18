#include <forward_list>
using std::forward_list;
#include <iostream>
using std::cout; using std::endl;

void deleta_odd_number(forward_list<int> &iflist)
{
    auto it = iflist.begin();
    auto it_pre = iflist.before_begin();

    while (it != iflist.end())
    {
        if (*it & 0x1)
        {
            it = iflist.erase_after(it_pre);
        }
        else
        {
            it_pre = it;
            ++it;
        }
    }
}

int main()
{
    forward_list<int> iflist{0, 1, 1, 2, 3, 4, 5};

    deleta_odd_number(iflist);

    for (auto &i : iflist)
    {
        cout << i << endl;
    }
    return 0;
}