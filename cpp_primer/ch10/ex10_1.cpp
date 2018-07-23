#include <algorithm>
using std::count;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> ivec{0, 1, 0, 2, 0, 3};
    cout << "共有" << count(ivec.cbegin(), ivec.cend(), 0) << "个0 " << endl;

    return 0;
}