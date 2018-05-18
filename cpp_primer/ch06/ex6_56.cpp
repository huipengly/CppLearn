#include <vector>
using std::vector;
#include <iostream>                 //错误2：没有包含iostream就用了cout
using std::cout; using std::endl;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    vector<int (*)(int, int)> func_vec;
    func_vec.push_back(add);                  //错误1：(func_vec.add(add))。vector增加内容是push_back
    func_vec.push_back(subtract);
    func_vec.push_back(multiply);
    func_vec.push_back(divide);

    cout << "1 + 2 = " << func_vec[0](1, 2) << endl;
    cout << "4 - 6 = " << func_vec[1](4, 6) << endl;
    cout << "9 * 9 = " << func_vec[2](9, 9) << endl;
    cout << "8 / 2 = " << func_vec[3](8, 2) << endl;

    return 0;
}