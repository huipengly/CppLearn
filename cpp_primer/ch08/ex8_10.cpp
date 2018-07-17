#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

void read_file()
{
    ifstream ifs("test_for_ex8_4.txt");
    if (!ifs)    // 需要判断文件读取是否成功
    {
        cerr << "No data?" << endl;
        return;
    }
    string line;
    vector<string> linevec;

    while(getline(ifs, line))
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