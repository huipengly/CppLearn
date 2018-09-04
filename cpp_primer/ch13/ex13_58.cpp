#include <iostream>
using namespace std;

class Foo
{
public:
    Foo sorted() const &
    {
        Foo ret(*this);
        cout << "Foo sorted() const &" << endl;
        return ret.sorted();
    }
    // Foo sorted() const &
    // {
    //     cout << "Foo sorted() const &" << endl;
    //     return Foo(*this).sorted();
    // }

    Foo sorted() &&
    {
        cout << "Foo sorted() &" << endl;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    Foo f1;
    f1.sorted();
    return 0;
}
