#include <iostream>
using namespace std;

template <typename> class t1;

template <typename T>
    void use_private(t1<T> &);

template <typename T>
class t1
{
    friend void use_private<T>(t1<T> &);
    int a = 0;
public:
    int aa() { return a; }
};

template <typename T>
void use_private(t1<T> &t)
{
    t.a = 1;
}

int main(int argc, char const *argv[])
{
    t1<int> t;
    cout << t.aa() << endl;
    use_private(t);
    cout << t.aa() << endl;
    return 0;
}
