/**
 * @brief 练习13.16
 * 
 * @file ex13_16.cpp
 * @author huipengly
 * @date 2018-09-02
 */

#include <iostream>
using std::cout; using std::endl;

class numbered
{
public:
    numbered() : mysn_(number) {}
    int mysn() { return mysn_; }
private:
    static int number;
    int mysn_;
};

int numbered::number = 0;

void f(numbered &s)
{
    cout << s.mysn() << endl;
}

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a);       // 0
    f(b);       // 0
    f(c);       // 0
    return 0;
}
