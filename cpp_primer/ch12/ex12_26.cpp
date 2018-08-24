/**
 * @brief 练习12.26
 * 
 * @file ex12_26.cpp
 * @author huipengly
 * @date 2018-08-24
 * @note allocator申请的空间不能使用delete释放
 */
#include <memory>
using std::allocator;
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

int main(int argc, char const *argv[])
{
    const int n = 100;
    allocator<string> alloc;
    string *const p = alloc.allocate(n);

    string s;
    string *q = p;

    while (cin >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }

    const size_t size = q - p;

    cout << "input number is " << size << endl;
    for (string *r = p; r != q; ++r)
    {
        cout << *r << endl;
    }

    // 这里不能使用delete []
    alloc.destroy(p);
    alloc.deallocate(p, n);
    
    return 0;
}
