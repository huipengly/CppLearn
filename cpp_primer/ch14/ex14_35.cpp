#include <iostream>
#include <string>
using namespace std;

class ReadString
{
public:
    ReadString(istream &is = cin) : is_(is) {}
    string operator()()
    { 
        string str;
        getline(is_, str);
        return str;
    }
private:
    istream &is_;
};

int main(int argc, char const *argv[])
{
    ReadString reader;
    string s = reader();
    cout << s << endl;
    return 0;
}
