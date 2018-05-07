#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    int read_int{0};
    vector<int> ivec;
    while (cin >> read_int)//要输入非数字才会跳出，有问题
    {
        ivec.push_back(read_int);
    }
    for (auto it = ivec.begin(); it != ivec.end() - 1; ++it)
    {
        cout << *it + *(it + 1) << endl;
    }
    return 0;
}