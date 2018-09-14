#include <string>
#include <iostream>
using namespace std;

template <typename T, typename ... Args> void f(const T &t, const Args& ... rest)
{
    cout << "Args : " << sizeof...(Args) << '\t';
    cout << "rest : " << sizeof...(rest) << endl;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";
    f(i, s, 42, d);
    f(s, 42, "hi");
    f(d, s);
    f("hi");
    return 0;
}
