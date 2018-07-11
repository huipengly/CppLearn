#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Screen
{
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos wd, pos ht, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[ r * width + c]; }
    Screen move(pos r, pos c) { cursor = r * width + c; return *this; }
    Screen set(char c) { contents[cursor] = c; return *this; }
    Screen set(pos r, pos col, char ch) { contents[r * width + col] = ch; return *this; }
    Screen display(ostream &os) { do_display(os); return *this; }
    const Screen display(ostream &os) const { do_display(os); return *this; }

private:
    void do_display(ostream &os) const { os << contents; }
    pos height;         //高度
    pos width;          //宽度
    pos cursor;         //光标

    string contents;
};