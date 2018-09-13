#include <list>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print(const T& t)
{
    using size_type = typename T::size_type;
    auto size = t.size();
    for (size_type i = 0; i != size; ++i)
    {
        cout << t[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    vector<double> dvec{0.1, 0.2, 0.3};    
    print(ivec);
    print(dvec);
    return 0;
}
