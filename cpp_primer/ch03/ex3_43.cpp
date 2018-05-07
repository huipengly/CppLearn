#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = { 0 };
    // ver.1
    cout << "ver.1" << endl;
    for (int (*row)[4] : ia)
    {
        for (int *col : row)
        {
            cout << *col << " ";
        }
        cout << endl;
    }
    return 0;
}