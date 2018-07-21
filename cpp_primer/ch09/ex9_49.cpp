#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl; using std::cerr; using std::istream;
#include <fstream>
using std::ifstream;

string ascender = "bdfhkIt";
string descender = "gjpqy";

void print_withou_word_with_ascender_and_descender(istream &is)
{
    string word;
    while (is >> word)
    {
        if (word.find_first_of(ascender) == string::npos && word.find_first_of(descender) == string::npos)
        {
            cout << word << ' ';
        }
    }
    cout << endl;
}

int main()
{
    ifstream ifs("data_for_ex9_49.txt");
    if (!ifs)       //这么写，后面函数的缩进少一点
    {
        cerr << "open file failed!" << endl;
        return -1;
    }
    print_withou_word_with_ascender_and_descender(ifs);
    return 0;
}