#include <iostream>
using std::cout; using std::endl; using std::cerr;
#include <string>
using std::string;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Please input two strings";
        return 0;
    }
    else
    {
        string str1{argv[1]};
        string str2{argv[2]};

        cout << str1+str2 << endl;
    }
    return 0;
}