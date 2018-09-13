#include <list>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print(const T& t)
{
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    vector<double> dvec{0.1, 0.2, 0.3};    
    list<double> dlist{0.1, 0.2, 0.3};    
    print(ivec);
    print(dvec);
    print(dlist);
    return 0;
}
