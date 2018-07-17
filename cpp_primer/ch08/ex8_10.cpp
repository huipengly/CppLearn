#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout; using std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

void read_file()
{
    ifstream in("test_for_ex8_4.txt");
    string line;
    vector<string> linevec;

    while(getline(in, line))
    {
        linevec.push_back(line);
    }

    for (auto &lines : linevec)
    {
        istringstream isstrm(lines);
        string word;
        while (isstrm >> word)
        {
            cout << word << endl;
        }
    }
}

int main()
{
    read_file();
    return 0;
}