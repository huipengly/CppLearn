#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    string s;
    string fmt = "$2.$5.$7";
    while (getline(cin, s))
    {
        cout << regex_replace(s, r, fmt) << endl;
    }
    return 0;
}
