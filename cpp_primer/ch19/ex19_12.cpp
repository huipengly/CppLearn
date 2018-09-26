#include <iostream>
#include "Screen.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Screen s(2, 2, 'x');
    auto pdata = Screen::data();
    cout << s.*pdata << endl;
    return 0;
}
