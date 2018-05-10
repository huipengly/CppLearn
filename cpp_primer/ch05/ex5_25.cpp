#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <exception>    //错误1：没有加入一场头文件
using std::runtime_error;

int main()
{
    int i1 = 0, i2 = 0;
    cout << "Please input two number." << endl;

    cin >> i1 >> i2;
    try
    {
        if (i2 == 0)
        {
            throw runtime_error("除数为0.");
        }
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl; //错误2：what()返回的是一个字符串，需要用cout输出
                                    //错误3：没有加入endl刷新输出
        return 0;
    }

    cout << i1 << " / " << i2 << " = " << i1/i2 << endl;//错误3：没有加入输出目标
    return 0;
}