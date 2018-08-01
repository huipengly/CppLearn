#include <map>
using std::map;
#include <list>
using std::list;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <algorithm>
using std::transform;

int main()
{
    map<string, list<int>> word_count;
    string line;
    int line_count = 0;
    while (getline(cin, line))
    {
        ++line_count;       // 第一行认为是1
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            string::size_type pos = string::npos;
            transform(word.begin(), word.end(), word.begin(), tolower);
            if ((pos = word.find_first_of(",.?!")) != string::npos)
            {
                word.erase(pos);
            }
            word_count[word].push_back(line_count);
        }
    }

    for (auto &w : word_count)
    {
        cout << "word : " << w.first << endl;
        for (auto &n : w.second)
        {
            cout << n << "\t";
        }
        cout << endl;
    }
    return 0;
}