#include "../ch13/String.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    String s("sjdalf;kjalkg");
    cout << s << endl;
    if (s != "sfg")
        cout << "ok1" << endl;
    if (s == "sjdalf;kjalkg")
        cout << "ojbk" << endl;
    return 0;
}
