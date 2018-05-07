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
    // for (int buffer; cin >> buffer; ivec.push_back(buffer));//github上的写法
    cout << "please input some number!" << endl;
    while (cin >> read_int)//要输入非数字才会跳出，有问题//linux下面输入ctrl+d作为文件结束符
    {
        ivec.push_back(read_int);
    }
    if(ivec.size() < 2)
    {
        cout << "please input 2 number at least!" << endl;
        return -1;
    }
    cout << "result" << endl;
    for (auto it = ivec.begin(); it != ivec.end() - 1; ++it)
    {
        cout << *it + *(it + 1) << endl;
    }
    return 0;
}