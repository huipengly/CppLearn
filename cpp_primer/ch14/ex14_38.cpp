#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class CompareSize
{
public:
    CompareSize(int sz) : sz_(sz) {}
    bool operator()(string &str) { return str.size() == sz_; }
private:
    int sz_;
};

int main(int argc, char const *argv[])
{
    if (argc < 1)
    {
        cerr << "please input file." << endl;
        return -1;
    }
    fstream input(argv[1]);
    if (!input)
    {
        cerr << "open file failed." << endl;
        return -2;
    }
    vector<string> svec;
    string str;
    while (input >> str)
    {
        svec.push_back(str);
    }
    int count[10]{};        // 值初始化？？？
    for (int i = 1; i != 11; ++i)
    {
        count[i - 1] = count_if(svec.begin(), svec.end(), CompareSize(i));
    }
    int more_than_10 = svec.size();
    for (int i = 0; i != 9; ++i)
    {
        more_than_10 -= count[i];
    }
    for (auto i : count)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << more_than_10 << endl;
    return 0;
}
