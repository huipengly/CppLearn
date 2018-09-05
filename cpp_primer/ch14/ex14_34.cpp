#include <iostream>
using namespace std;

class if_then_else
{
public:
    int operator()(bool a, int b, int c)
    {
        return a ? b : c;
    }
};

int main()
{
    if_then_else if_then_else_obj;
    cout << if_then_else_obj(true, 1, 2) << endl;
    cout << if_then_else_obj(false, 1, 2) << endl;
    return 0;
}