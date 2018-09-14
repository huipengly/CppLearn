#include <iostream>
#include <memory>
#include "my_make_shared.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 1;
    shared_ptr<int> pi = my_make_shared<int>(i);
    cout << *pi << endl;
    return 0;
}
