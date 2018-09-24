#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string pattern = "[^c]ei";
    pattern = "[[:alpfha:]]*" + pattern + "[[:alpha:]]*";
    try{
    regex re(pattern);
    }
    catch (regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    regex r(pattern);
    smatch results;
    string in;
    while (cin >> in)
    {
        try{
            if (regex_search(in, results, r))
            {
                cout << "wrong word is " << results.str() << endl;
            }
        }
        catch (regex_error e)
        {
            cout << e.what() << "\ncode: " << e.code() << endl;
        }
    }
    return 0;
}
