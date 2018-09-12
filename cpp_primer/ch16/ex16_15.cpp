#include "Screen.h"
#include <iostream>
using std::cout;

int main()
{
    Screen<5, 5> myScreen('X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}