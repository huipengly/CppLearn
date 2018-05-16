#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

//最初设想的是只给vector，不能用。又想用迭代器，但是觉得不优雅。看了GitHub，发现用的是迭代器。
void print_vector(vector<string>::iterator begin, vector<string>::iterator end)
{
    if (begin != end)
    {
        cout << *begin;
        print_vector(++begin, end);
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    vector<string> str = {"hello", " ", "world", "!"};
    print_vector(str.begin(), str.end());
    return 0;
}