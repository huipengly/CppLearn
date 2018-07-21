#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

void add_prefix_and_postfix(string &s, const string &prefix, const string &postfix)
{
    s.insert(s.begin(), 1, ' ');
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(" ");
    s.append(postfix);
}

int main()
{
    string name = "huipeng";
    add_prefix_and_postfix(name, "Mr.", "Jr.");     //Sr 和Jr 分别表示同姓的老一辈和小一辈。senior, junior
    cout << name << endl;

    return 0;
}