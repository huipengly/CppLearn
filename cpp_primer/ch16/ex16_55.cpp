#include <vector>
#include <iostream>
using namespace std;

template <typename T, typename ... Args>
void print(ostream &os, const T &t, const Args& ... rest)
{
    os << t << ", ";
    print(os, rest...);         // Hints:这边是rest...不是..rest
}

// template <typename T>
// void print(ostream &os, const T &t)
// {
//     os << t;
// }

int main(int argc, char const *argv[])
{
//    print(cout, 1);
    cout << endl;
    print(cout, 1, 1.4);
    cout << endl;
    print(cout, 1, 3.14, "hello", string("world"), 40);
    cout << endl;
    // vector<int> ivec{1, 2, 3};   // 报错
    // print(cout, 1, ivec);
    return 0;
}
