#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main(int argc, char const *argv[])
{
    vector<pair<string, int>> vec_of_pair_string_int;
    int number;
    string str;
    while (cin >> str && cin >> number)
    {
        vec_of_pair_string_int.push_back({str, number});
    }

    for (auto &v : vec_of_pair_string_int)
    {
        cout << v.first << '\t' << v.second << endl;
    }
    return 0;
}
