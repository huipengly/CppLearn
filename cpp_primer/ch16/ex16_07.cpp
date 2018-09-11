#include <iostream>
using namespace std;

template <typename T, unsigned N> constexpr
unsigned size(const T (&array)[N])
{
    return N;
}

int main(int argc, char const *argv[])
{
    char a[100]{0};
    cout << size(a) << endl;
    return 0;
}
