/**
 * @brief 练习18.1
 * 
 * @file ex18_01.cpp
 * @author huipengly
 * @date 2018-09-25
 * 
 * 在下列 throw 语句中异常对象的类型是什么？
 * 
 * (a) range_error r("error");
 * 	    throw r;
 * (b) exception *p = &r;
 * 	    throw *p;
 * 
 * 如果将(b)中的throw语句写成throw p将发生什么
 * 
 * 个人理解：若r在局部声明的，当栈展开时，r被释放，那么p所指的内存空间存储内容不确定，所以是未定义行为。
 * 但是我不知道如何写成程序验证
 */

#include <exception>
#include <stdexcept>
using namespace std;

void func1()
{
    range_error r("error");

    exception *p = &r;
    throw p;
}

int main(int argc, char const *argv[])
{
    try{
        func1();
    }
    catch (exception *p)
    {
        throw *p;
    }
    // range_error r("error");
    // // throw r;

    // exception *p = &r;
    // throw p;
    return 0;
}
