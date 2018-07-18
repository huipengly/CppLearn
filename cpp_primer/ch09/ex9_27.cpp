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

// github写法
auto remove_odds(forward_list<int>& flist)
{
    auto is_odd = [] (int i) { return i & 0x1; };
    flist.remove_if(is_odd);
}

int main()
{
    forward_list<int> iflist{0, 1, 1, 2, 3, 4, 5};

    remove_odds(iflist);

    for (auto &i : iflist)
    {
        cout << i << endl;
    }
    return 0;
}