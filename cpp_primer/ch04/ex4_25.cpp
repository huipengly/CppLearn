#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int q = 0b01110001;
    cout << (~q<<6) << endl;
    return 0;
}