#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <typename T> string debug_rep(const T&);
template <typename T> string debug_rep(T*);
string debug_rep(const string&);
string debug_rep(const char* str)
{
    return debug_rep(string(str));
}

string debug_rep(char* str)
{
    return debug_rep(string(str));
}

template <typename T> string debug_rep(const T& rep)
{
    ostringstream ret;
    ret << rep;
    return ret.str();           // 要返回一个string的副本，而不是返回ret
}

template <typename T> string debug_rep(T *p)
{
    ostringstream ret;
    ret << "pointer: " << p << " ";
    if (p)
        ret << debug_rep(*p);
    else
        ret << " null pointer.";
    return ret.str();
}

string debug_rep(const string& str)
{
    return '"' + str + '"';
}

int main(int argc, char const *argv[])
{
    string s("s");
    string *sp = new string("sp");
    cout << debug_rep(s) << endl;
    cout << debug_rep(sp) << endl;
    cout << debug_rep("const char *") << endl;
    return 0;
}
