#include <cstdlib>
#include <iostream>

using namespace std;

class Parent
{
public:
    Parent()
    {
    }
    
    virtual void func()
    {
        cout<<"void Parent::func()"<<endl;
    }

    void test()
    {
        this->func();
    }
};

class Child : public Parent
{
public: 
    void func()
    {
        cout<<"void Child::func()"<<endl;
    }
};

int main(int argc, char *argv[])
{
    Child c;

    c.test();
    
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
