#include <iostream>
using namespace std;
template <typename T, unsigned N>
T begin(const T (&array)[N])
{
    return array;
}

template <typename T, unsigned N>
T end(const T (&array)[N])
{
    return array + N;
}

int main(int argc, char const *argv[])
{
    int arr[3] = {1, 2, 3};
    cout << *begin(arr) << endl;
    cout << *(end(arr) - 1) << endl;
    return 0;
}
