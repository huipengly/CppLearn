#include <utility>
#include <iostream>
using namespace std;

template <typename F, typename T1, typename T2>
void flipe(F f, T1 &&t1, T2 &&t2)
{
    return f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f1(int a, int b)
{
    ++a;
    ++b;
    cout << a << " " << b << endl;
}

void f2(int &a, int &&b)
{
    ++a;
    ++b;
    cout << a << " " << b << endl;
}

int main(int argc, char const *argv[])
{
    int a = 3, b = 4;
    flipe(f1, a, b);
    cout << a << " " << b << endl;
    flipe(f2, std::move(a), b);
    cout << a << " " << b << endl;
    return 0;
}
