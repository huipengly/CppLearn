#include <forward_list>
using std::forward_list;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

void add_string(forward_list<string> &sflist, const string &s1, const string &s2)
{
    bool never_find_s1 = true;
    auto it = sflist.begin();
    auto it_pre = sflist.before_begin();

    while (it != sflist.end())
    {
        if (*it == s1)
        {
            it = sflist.insert_after(it, s2);
            ++it_pre;
            never_find_s1 = false;
        }
        else
        {
            it_pre = it;
            ++it;
        }
    }

    if (never_find_s1)
    {
        sflist.insert_after(it_pre, s2);
    }
}

int main()
{
    forward_list<string> sflist1{"hello", "world", "hui", "peng"}, sflist2{"hello", "world", "world", "hui", "peng"}, sflist3{sflist1};
    string s1{"world"}, s2{"!"}, s3{"huipeng"};
    add_string(sflist1, s1, s2);
    add_string(sflist2, s1, s2);
    add_string(sflist3, s3, s2);

    cout << "1" << endl;
    for (auto &s : sflist1)
    {
        cout << s << endl;
    }

    cout << "2" << endl;
    for (auto &s : sflist2)
    {
        cout << s << endl;
    }

    cout << "3" << endl;
    for (auto &s : sflist3)
    {
        cout << s << endl;
    }
    return 0;
}