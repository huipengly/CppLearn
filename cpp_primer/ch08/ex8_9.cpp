#include <iostream>
using std::istream; using std::cout; using std::endl; using std::cin;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

istream &print_stream(istream &is)
{
    string s;
    while(!is.eof())
    {
        is >> s;
        cout << s << endl;
    }

    cout << is.rdstate() << endl;
    is.clear();
    cout << is.rdstate() << endl;

    return is;
}

int main()
{
    // string s("test a b c");
    // istringstream info(s);
    istringstream info("test a b c");
    istream &is = print_stream(info);        //必须声明为引用，因为IO不能拷贝或赋值
    cout << is.rdstate() << endl;

    return 0;
}