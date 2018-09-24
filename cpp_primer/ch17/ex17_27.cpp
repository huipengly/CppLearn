#include <regex>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string zip = "(\\d{5})([-])?(\\d{4})?";
    regex r(zip);
    string s;
    string fmt = "$1.$3";
    // while (getline(cin, s))
    s = "00000-0000 000100000";
    {
        cout << regex_replace(s, r, fmt) << endl;
    }
    return 0;
}
