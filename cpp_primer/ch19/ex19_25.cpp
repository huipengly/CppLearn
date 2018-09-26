#include <string>
#include "token.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data item("978-7-121-20038-0", 12, 128.0);
    char c = 'c';
    int i = 10;
    double d = 3.14;
    string s = "string";

    Token t;
    cout << t << endl;
    t = c;
    cout << t << endl;
    t = i;
    cout << t << endl;
    t = d;
    cout << t << endl;
    t = s;
    cout << t << endl;
    t = item;
    cout << t << endl;

    Token t2(t);
    cout << t2 << endl;
    t2 = c;
    cout << t2 << endl;
    t2 = i;
    cout << t2 << endl;
    t2 = d;
    cout << t2 << endl;
    t2 = s;
    cout << t2 << endl;
    t2 = item;
    cout << t2 << endl;

    Token t3(std::move(t));
    cout << t3 << endl;
    t3 = c;
    cout << t3 << endl;
    t3 = i;
    cout << t3 << endl;
    t3 = d;
    cout << t3 << endl;
    t3 = s;
    cout << t3 << endl;
    t3 = item;
    cout << t3 << endl;

    return 0;
}
