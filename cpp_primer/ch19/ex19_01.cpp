#include "my_new_delete.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *p = new int(10);
    cout << *p << endl;
    delete p;
    return 0;
}
