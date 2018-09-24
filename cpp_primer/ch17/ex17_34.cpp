#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << boolalpha << true << " " << false << endl;
    cout << noboolalpha << true << " " << false << endl;

    cout << showbase;
    cout << oct << 1024 << endl;
    cout << dec << 1024 << endl;
    cout << hex << 1024 << endl;

    cout << noshowbase;
    cout << oct << 1024 << endl;
    cout << dec << 1024 << endl;
    cout << hex << 1024 << endl << dec;

    cout << showpoint << 10.0 << endl;
    cout << noshowpoint << 10.0 << endl;

    cout << showpos << 10 << endl;
    cout << noshowpos << 10 << endl;

    cout << hex << uppercase << 1024 << endl;
    cout << dec << nouppercase;

    cout << showpos;
    cout << left << setw(10) << 123 << "next col" << endl;
    cout << right << setfill('$') << setw(10) << 123 << "next col" << endl;
    cout << internal << setw(10) << 123 << "next col" << endl;

    return 0;
}
