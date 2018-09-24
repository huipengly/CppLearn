#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string pattern = "[^c]ei";
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string in;
    while (cin >> in)
    {
        if (regex_search(in, results, r))
        {
            cout << "wrong word is " << results.str() << endl;
        }
    }
    return 0;
}
