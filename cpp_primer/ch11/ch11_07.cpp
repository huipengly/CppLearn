#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    map<string, vector<string>> family;
    string first_name, family_name;
    while (cin >> first_name && cin >> family_name)
    {
        family[family_name].push_back(first_name);
    }

    for (auto &f : family)
    {
        cout << "family name is " << f.first << endl;
        for (auto &name : f.second)
        {
            cout << name << "\t";
        }
        cout << endl;
    }
    return 0;
}