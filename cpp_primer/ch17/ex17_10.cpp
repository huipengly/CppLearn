#include <bitset>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bitset<32> b1("1000000010000100101110");
    bitset<32> b2;
    b2.set(1).set(2).set(3).set(5).set(8).set(13).set(21);
    cout << b1 << endl;
    cout << b2 << endl;
    return 0;
}
