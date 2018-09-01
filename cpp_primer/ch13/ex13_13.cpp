#include "ex13_13.h"
#include <memory>
using std::shared_ptr;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

void fun1(X x) {}
void fun2(X &x) {}
void fun3()
{
    shared_ptr<X> px(new X);
}
void fun4()
{
    X *px = new X;
    delete px;
}
void fun5()
{
    X *px = new X;
}
void fun6(X &x)
{
    cout << "vector<X> vecX;" << endl;
    vector<X> vecX;
    vecX.reserve(100);      // 不加这个临时多分配变量时，后面的push_back可能还会引起内存的拷贝，不是题目为了观察的内容。
    cout << "vecX.push_back(X());" << endl;
    vecX.push_back(X());    // 构造临时x，拷贝构造push的，析构临时x
    cout << "vecX.push_back(X());" << endl;
    vecX.push_back(X());    // 构造临时x，拷贝构造push的，析构临时x
    cout << "vecX.pop_back();" << endl;
    vecX.pop_back();        // 析构vector里最后一个x
    // 析构vector里剩下的一个x
}

int main(int argc, char const *argv[])
{
    X x1;           // x的构造函数
    X x2 = x1;      // x的构造函数，x的拷贝赋值函数         // 理解错误，这里也是使用拷贝构造函数
    X x3(x2);       // x的拷贝构造函数
    x1 = x3;        // 添加的，这里调用拷贝赋值函数
    
    cout << "fun1" << endl;
    fun1(x1);       // 传参，调用构造函数，函数结束调用析构函数
    cout << "fun2" << endl;
    fun2(x2);       // 传引用，不构造，不析构
    cout << "fun3" << endl;
    fun3();         // 智能指针，new时构造，函数结束时counter减为0，调用析构
    cout << "fun4" << endl;
    fun4();         // 内置指针，new时构造，delete时析构
    cout << "fun5" << endl;
    fun5();         // 内置指针，new时构造，没有delete，不析构，造成内存泄漏
    cout << "fun6" << endl;
    fun6(x1);       // 容器
    cout << "end fun6" << endl;
    return 0;
    // 离开时，x1、x2、x3析构
}
