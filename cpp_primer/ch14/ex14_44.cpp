#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

class Multiplie
{
public:
    int operator()(int a, int b) { return a * b; }
};

int main(int argc, char const *argv[])
{
    auto mod = [](int a, int b) { return a % b; };
    map<string, function<int(int, int)>> binops;
    binops["+"] = add;
    binops["-"] = minus<int>();
    binops["*"] = Multiplie();
    binops["/"] = [](int a, int b) { return a / b; };
    binops["%"] = mod;

    int a, b;
    char c;
    while (cin >> a >> c >> b)
    {
        cout << a << " " << c << " " << b << " = " << binops[string(&c)](a, b) << endl;
    }
    return 0;
}
