#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

void print_vector(vector<string>::iterator str)
{
    if (str.begin() != str.end() - 1)
    {
        cout << *str.begin();
        print_vector(*(str.begin() + 1))
    }
    else
    {
        cout << *str.begin();
    }
}

int main()
{
    vector<string> str = {"hello", " ", "world", "!"};
    print_vector(str);
    return 0;
}