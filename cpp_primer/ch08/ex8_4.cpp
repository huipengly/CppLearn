#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

void read_line()
{
    vector<string> svec;
    ifstream in;
    in.open("test_for_ex8_4.txt");

    while (in)
    {
        string s;
        getline(in, s);
        svec.push_back(s);
    }

    for (auto s : svec)
    {
        cout << s << endl;
    }
}

int main()
{
    read_line();

    return 0;
}