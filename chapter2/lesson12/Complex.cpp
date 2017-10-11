//操作符重载 复数相加和输出
#include <iostream>

using namespace std;

class Complex
{
  private:
    int a;
    int b;

  public:
    Complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    int Geta()
    {
        return a;
    }

    int Getb()
    {
        return b;
    }

    friend Complex operator+(const Complex &ret1, const Complex &ret2);
    // friend Complex operator+(Complex ret1, Complex ret2);
    friend ostream &operator<<(ostream &out, Complex c);
};

Complex operator+(const Complex &ret1, const Complex &ret2)
//const &变量有什么用？ const使变量变为只读，不会被函数修改。&是引用，直接操作实参。我的猜想是const &可以节约内存空间，进入函数时不生成形参，并且加了const之后实参不会被函数改变。
// Complex operator+(Complex ret1, Complex ret2)
{
    Complex ret;

    ret1.a = 10;

    ret.a = ret1.a + ret2.a;
    ret.b = ret1.b + ret2.b;

    return ret;
}

ostream &operator<<(ostream &out, Complex c)
{
    out << c.a << " + " << c.b << "i";

    return out;
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;

    /*   cout<<"c1.a = "<<c1.Geta()<<endl;
    cout<<"c1.b = "<<c1.Getb()<<endl;
    cout<<"c2.a = "<<c2.Geta()<<endl;
    cout<<"c2.b = "<<c2.Getb()<<endl;
    cout<<"c3.a = "<<c3.Geta()<<endl;
    cout<<"c3.b = "<<c3.Getb()<<endl;*/

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;

    return 0;
}