#include <iostream>
#include "feb.h"

using namespace std;

int main()
{
    cout << "int feb1(int i)" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << feb1(i+1) << endl;
    }

    cout << "int feb2()" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << feb2() << endl;
    }

    cout << "class feb" << endl;

    feb f1;

    for (int i = 0; i < 10; i++)
    {
        cout << f1() << endl;
    }

    cout << "class feb f2" << endl;

    feb f2;

    for (int i = 0; i < 5; i++)
    {
        cout << f2() << endl;
    }

    return 0;
}