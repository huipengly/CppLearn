#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ReadString
{
public:
    ReadString(istream &is = cin) : is_(is) {}
    string operator()()
    { 
        string str;
        is_ >> str;
        return str;
    }
private:
    istream &is_;
};

int main(int argc, char const *argv[])
{
    ReadString reader;
    vector<string> vecs;
    vecs.push_back(reader());
    vecs.push_back(reader());
    vecs.push_back(reader());
    vecs.push_back(reader());
    for (auto &s : vecs)
    {
        cout << s << endl;
    }
    return 0;
}
