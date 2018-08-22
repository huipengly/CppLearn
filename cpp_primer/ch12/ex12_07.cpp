/**
 * @brief ??12.7
 * 
 * @file ex12_07.cpp
 * @author huipengly
 * @date 2018-08-22
 */
#include <memory>
using std::shared_ptr; using std::make_shared;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl; using std::cin;

void read(shared_ptr<vector<int>> pvi)
{
    int i;
    while (cin >> i)
    {
        pvi->push_back(i);
    }
}

void print(shared_ptr<vector<int>> pvi)
{
    for (auto i : *pvi)
    {
        cout << i << '\t';
    }
    cout << endl;
}

int main()
{
    auto pvi = make_shared<vector<int>>();
    read(pvi);
    print(pvi);
    return 0;
}