#include <iostream>
using std::cout; using std::endl;

void swap_by_point(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 0, b = 10;
    int *pa = &a, *pb = &b;             //错误1：*pa = a。指针初始化需要使用引用的形式赋值
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // swap_by_point(&a, &b);           //&a可以认为是a的引用，也可以认为是对a取地址。具体看形参
    swap_by_point(pa, pb);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}