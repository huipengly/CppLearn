#include <initializer_list>             //错误1：initializer_list拼错了
using std::initializer_list;
#include <iostream>
using std::cout; using std::endl;

int add(initializer_list<int> il)       //错误2：initializer_list需要实例化
{
    int ret = 0;
    for (const auto i : il)
    {
        ret += i;
    }

    return ret;
}

int main()
{
    int a = 3, b = 2;
    cout << add({a, b, 30}) << endl;
    return 0;
}