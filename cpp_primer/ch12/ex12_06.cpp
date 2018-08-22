/**
 * @brief 练习12.6
 * 
 * @file ex12_06.cpp
 * @author huipengly
 * @date 2018-08-22
 */
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl; using std::cin;

vector<int>* fun1()
{
    vector<int> *p = new vector<int>();
    return p;
}

void read(vector<int> *pvi)
{
    int i;
    while (cin >> i)
    {
        pvi->push_back(i);
    }
}

void print(vector<int> *pvi)
{
    for (auto i : *pvi)
    {
        cout << i << '\t';
    }
    cout << endl;
    delete pvi;
}

int main()
{
    auto pvi = fun1();
    read(pvi);
    print(pvi);
    return 0;
}