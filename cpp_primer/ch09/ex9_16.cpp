#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

bool if_equal(vector<int> ivec, list<int> ilist)
{
    auto vec_begin = ivec.begin();
    auto list_begin = ilist.begin();
    while (vec_begin != ivec.end() && list_begin != ilist.end())
    {
        if (*vec_begin != *list_begin)
        {
            return false;
        }
        ++vec_begin;
        ++list_begin;
    }
    if (vec_begin == ivec.end() && list_begin == ilist.end())
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> ivec{1, 2, 3, 4, 7};
    list<int> ilist{1, 2, 3, 4, 7, 9};

    if (if_equal(ivec, ilist))
    {
        cout << "equal!" << endl;
    }
    
    return 0;
}