#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::transform;

int main()
{
    map<string, int> word_count;
    string word;
    while (cin >> word)
    {
        string::size_type pos = string::npos;
        transform(word.begin(), word.end(), word.begin(), tolower);
        if ((pos = word.find_first_of(",.?!")) != string::npos)
        {
            word.erase(pos);
        }
        ++word_count[word];
    }

    for (auto &w : word_count)
    {
        cout << w.first << " : " << w.second << endl;
    }
    return 0;
}