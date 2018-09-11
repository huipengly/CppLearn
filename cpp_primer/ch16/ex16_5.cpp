#include <iostream>
using namespace std;

template <typename T, unsigned N>
void my_print(T (&arr)[N])
{
    for (auto elem : arr)
    {
        cout << elem << endl;
    }
}

int main(int argc, char const *argv[])
{
    double a[6] = {0, 1, 2, 3};
    my_print(a);
    return 0;
}
