#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

bool find_number(vector<int>::iterator begin, vector<int>::iterator end, const int number)
{
    while (begin != end)
    {
        if (*begin == number)
        {
            return true;
        }
        ++begin;
    }
    return false;
}

int main()
{
    vector<int> test_ivec{1, 3, 5, 7, 9, 2, 4, 6};
    int num1{3}, num2{10};

    if (find_number(test_ivec.begin(), test_ivec.end(), num1))
    {
        cout << "find num1!" << endl;
    }

    if (find_number(test_ivec.begin(), test_ivec.end(), num2))
    {
        cout << "find num2!" << endl;
    }
    return 0;
}