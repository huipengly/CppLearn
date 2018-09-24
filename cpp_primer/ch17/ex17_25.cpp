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
        smatch m;
        regex_search(s, m, r);
        if (!m.empty())
            cout << m.prefix().str() << regex_replace(m.str(), r, fmt) << endl;
    }
    return 0;
}
