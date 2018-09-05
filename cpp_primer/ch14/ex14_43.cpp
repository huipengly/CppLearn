#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main()
{
    vector<int> ivec{2, 4, 8, 16};
    std::modulus<int> mod;
    if (none_of(ivec.begin(), ivec.end(), bind(mod, 1024, _1)))
    {
        cout << "1024是" << endl;
    }
    if (none_of(ivec.begin(), ivec.end(), bind(mod, 1025, _1)))
    {
        cout << "1025是" << endl;
    }
    return 0;
}