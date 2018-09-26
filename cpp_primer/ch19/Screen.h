#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
using std::string;
#include <iostream>
using std::ostream;
#include <vector>
using std::vector;

class Screen;

class WindowMgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    //vector<Screen> screens{Screen(24, 80, ' ')};      //报错，不能在定义Screen之前使用其构造函数
    vector<Screen> screens;
};

class Screen
{
    friend void WindowMgr::clear(ScreenIndex);

public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos wd, pos ht, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[ r * width + c]; }
    Screen &move(pos r, pos c) { cursor = r * width + c; return *this; }
    Screen &set(char c) { contents[cursor] = c; return *this; }
    Screen &set(pos r, pos col, char ch) { contents[r * width + col] = ch; return *this; }
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }
    pos size();
    static const pos Screen::*data() { return &Screen::cursor; }        // Hints: pos前不需要家Screen::，cursor前要加Screen::

private:
    void do_display(ostream &os) const { os << contents; }
    pos height;         //高度
    pos width;          //宽度
    pos cursor;         //光标

    string contents;
};

inline Screen::pos Screen::size()
{
    return width * height;
}

void WindowMgr::clear(ScreenIndex screen_index)     //卸载后面是因为需要Screen完成定义
{
    if (screen_index < screens.size())              //安全性判断
    {
        Screen &s = screens[screen_index];          //增加别名，提高程序可读性
        s.contents = string(s.width * s.height, ' ');
    }
}

#endif // _SCREEN_H_