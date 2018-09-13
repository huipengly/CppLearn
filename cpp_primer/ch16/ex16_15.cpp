#include "Screen.h"
#include <iostream>
using namespace std;

int main()
{
    Screen<5, 5> myScreen('X');
    // myScreen.move(4, 0).set('#').display(cout);
    // cout << '\n';
    // myScreen.display(cout);
    // // cout << myScreen << endl;
    myScreen.move(0, 0);
    cin >> myScreen;
    // cout << endl << "aaa :";
    // aa(myScreen);
    // myScreen.display(cout);
    cout << myScreen << endl;
    return 0;
}