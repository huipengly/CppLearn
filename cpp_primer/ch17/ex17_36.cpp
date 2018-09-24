#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << left << setw(15) << uppercase << hexfloat << sqrt(2) << endl;        // Hints: 浮点数的16进制时hexfloat

    cout << dec << defaultfloat << endl;

    cout << setw(15) << 123.45 << "next col" << endl;
    cout << setw(15) << 1024.11 << "next col" << endl;

    return 0;
}
