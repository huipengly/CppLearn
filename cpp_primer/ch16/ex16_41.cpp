#include <iostream>
using namespace std;

template <typename L, typename R>
auto sum(L lhs, R rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main(int argc, char const *argv[])
{
    long double s = sum(10950483257940327904237057, 759043279058749032765908479067);
    cout << s << endl;
    return 0;
}
