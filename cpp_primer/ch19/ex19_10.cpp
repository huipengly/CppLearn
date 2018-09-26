#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
using std::type_info;
class A {
public:
    A() = default;
    virtual ~A() = default;
    // virtual void fun() = 0;
};
class B : public A {
public:
    B() = default;
    ~B() = default;
    // void fun() {};
};
class C : public B {
public:
    C() = default;
    ~C() = default;
    // void fun() {};
};
int main()
{
    A *pa = new C;
    cout << typeid(pa).name() << endl;
    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl;     // &ra是对变量ra取地址，得到一个指针，不是对象，所以是A*
    cout << typeid(ra).name() << endl;      // ra的话是对象，需要考虑动态绑定
    B *px = new B;
    A &ra1 = *px;
    cout << typeid(ra1).name() << endl;
}
// ******result of cl******
// class A *
// class A *
// class C
// class B
