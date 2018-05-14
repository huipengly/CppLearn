//验证函数传参传数组的定义
#include <iostream>
using std::cout; using std::endl;
#include <cstddef>
using std::size_t;//错误1：size_t没包含头文件就用了

// void print(const int ia[10])
// {
//     // for (size_t i = 0; i < 15; ++i)
//     // {
//     //     cout << ia[i] << endl;
//     // }

//     for (int i : ia)
//     {
//         cout << i << endl;
//     }
// }

// void print(const int ia[10])
// {
// 	for (size_t i = 0; i != 10; ++i)
// 		cout << ia[i] << endl;
// }

void print(const int (&ia)[10])
{
	// for (size_t i = 0; i != 15; ++i)
	// 	cout << ia[i] << endl;

    for (int i : ia)
    {
        cout << i << endl;
    }
}

int main()
{
    int iarr[10] = {0, 1, 2, 3};
    print(iarr);
    return 0;
}