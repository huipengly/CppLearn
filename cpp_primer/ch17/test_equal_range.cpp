#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5, 5, 5, 6};
    auto found = equal_range(ivec.cbegin(), ivec.cend(), 5);
    for (auto it = found.first; it != found.second; ++it)
    {
        cout << *it << "\t";
    }
    cout << endl;
    auto found = equal_range(ivec.cbegin(), ivec.cend(), 100);
    for (auto it = found.first; it != found.second; ++it)
    {
        cout << *it << "\t";
    }
    cout << endl;
    return 0;
}
