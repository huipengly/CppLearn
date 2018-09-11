#include "my_find.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    list<string> slst{"hello", "world", "visual", "code"};
    cout << *my_find(ivec.begin(), ivec.end(), 3) << endl;
    cout << *my_find(slst.begin(), slst.end(), "hello") << endl;
    return 0;
}
