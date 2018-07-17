#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

vector<int>::iterator find_number(vector<int>::iterator begin, vector<int>::iterator end, const int number)
{
    while (begin != end)
    {
        if (*begin == number)
        {
            return begin;
        }
        ++begin;
    }
    return begin;
}

int main()
{
    vector<int> test_ivec{1, 3, 5, 7, 9, 2, 4, 6};
    int num1{3}, num2{10};
    vector<int>::iterator num_it;

    num_it = find_number(test_ivec.begin(), test_ivec.end(), num1);
    if (find_number(test_ivec.begin(), test_ivec.end(), num1) != test_ivec.end())
    {
        cout << "find num1! : " << *num_it << endl;
    }

    num_it = find_number(test_ivec.begin(), test_ivec.end(), num1);
    if (find_number(test_ivec.begin(), test_ivec.end(), num2) != test_ivec.end())
    {
        cout << "find num2! : " << *num_it << endl;
    }
    return 0;
}