#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    map<string, int> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }

    for (auto &w : word_count)
    {
        cout << w.first << " : " << w.second << endl;
    }
    return 0;
}