#include <iostream>
using std::istream; using std::cout; using std::endl; using std::cin;
#include <string>
using std::string;

istream &print_stream(istream &is)
{
    string s;
    while(!is.eof())
    {
        is >> s;
        cout << s;
    }

    is.clear();

    return is;
}

int main()
{
    print_stream(cin);

    return 0;
}