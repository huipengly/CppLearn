/**
 * @brief 练习13.15
 * 
 * @file ex13_15.cpp
 * @author huipengly
 * @date 2018-09-02
 */

#include <iostream>
using std::cout; using std::endl;

class numbered
{
public:
    numbered() : mysn_(number) {}
    numbered(const numbered& num) { ++number; mysn_ = number; }
    numbered& operator=(numbered &num) { ++number; mysn_ = number; }
    int mysn() { return mysn_; }

private:
    static int number;
    int mysn_;
};

int numbered::number = 0;

void f(numbered s)
{
    cout << s.mysn() << endl;
}

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    f(a);       // 3
    f(b);       // 4
    f(c);       // 5
    return 0;
}
