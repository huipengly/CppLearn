#include <iostream>

class Father
{
private:
    int a;
protected:
    int b;
public:
    int c;

    Father()
    {
        a = 0;
        b = 0;
        c = 0;
    }
};

class Child : private Father
{
public:
    void set()
    {
   //     a = 10;
        b = 10;
        c = 10;
    }
};

// class ChildChild : private Father
// {
// public:
//     void sett()
//     {
//         this->c = 10;
//     }
// };

int main()
{

    return 0;
}