#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <utility>
using std::pair;

int main()
{
    map<string, vector<pair<string, string>>> family;
    string first_name, family_name, birthday;
    while (cin >> first_name && cin >> family_name && cin >> birthday)
    {
        family[family_name].push_back({first_name, birthday});
    }

    for (auto &f : family)
    {
        cout << "family name is " << f.first << endl;
        for (auto &info : f.second)
        {
            cout << info.first << "\t" << info.second << endl;
        }
    }
    return 0;
}