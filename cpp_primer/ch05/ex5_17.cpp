#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector; using std::swap;

int main()
{
    // 错误1：vector列表初始化不用等号！！，注释部分是错的
    // vector<int> ivec1 = {0, 1, 1, 2};
    // vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> ivec1{0, 1, 1, 2};
    vector<int> ivec2{0, 1, 1, 2, 3, 5, 8};
    bool ret = false;

    // 错误2：括号没有对称
    if (ivec1.size() > ivec2.size())
    {
        swap(ivec1, ivec2);
    }

    for (decltype(ivec1.size()) i = 0; i != ivec1.size(); ++i)
    {
        if (ivec1[i] != ivec2[i])
        {
            cout << "false" << endl;
            return 0;
        }
    }
    ret = true;
    cout << "true" << endl;
    return 0;
}