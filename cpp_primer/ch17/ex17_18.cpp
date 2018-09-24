#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    regex r1("albeit|neighbor", regex::icase);
    smatch results;
    string in;
    while (getline(cin, in))
    {
        for (sregex_iterator it(in.begin(), in.end(), r), end; it != end; ++it)
        {
            if (regex_search(it->str(), r1))
            {
                continue;
            }
            auto pos = it->prefix().length();
            pos = pos > 40 ? pos - 40 : 0;
            cout << it->prefix().str().substr(pos);
            cout << "\n\t\t>>> " << it->str() << " <<<\n";
            cout << it->suffix().str().substr(0, 40) << endl;
        }
    }
    return 0;
}
