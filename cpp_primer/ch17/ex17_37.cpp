#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char str[30] = "\0";
    while (cin.getline(str, 20, '\n'))
    {
        cout << str << endl;
    }
    return 0;
}
