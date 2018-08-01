#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::transform; using std::remove_if;
#include <cctype>

int main()
{
    map<string, int> word_count;
    string word;
    while (cin >> word)
    {
        string::size_type pos = string::npos;
        transform(word.begin(), word.end(), word.begin(), tolower);
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        ++word_count[word];
    }

    for (auto &w : word_count)
    {
        cout << w.first << " : " << w.second << endl;
    }
    return 0;
}