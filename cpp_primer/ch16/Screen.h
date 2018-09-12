#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
#include <iostream>
#include <vector>

template <std::string::size_type, std::string::size_type> class Screen;

template <std::string::size_type H, std::string::size_type W>
class WindowMgr
{
public:
    using ScreenIndex = typename std::vector<Screen<H, W>>::size_type;  // Hints:类型名需要加typename
    void clear(ScreenIndex);
private:
    //std::vector<Screen> screens{Screen(24, 80, ' ')};      //报错，不能在定义Screen之前使用其构造函数
    std::vector<Screen<H, W>> screens;
};

template <std::string::size_type H, std::string::size_type W>
class Screen
{
    friend void WindowMgr<H, W>::clear(WindowMgr<H, W>::ScreenIndex);   // Hints: 后面的ScreenIndex也需要定义域符，因为需要指定实例化的WindowMgr

public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(char c = ' ') : contents(H * W, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[ r * W + c]; }
    Screen &move(pos r, pos c) { cursor = r * W + c; return *this; }
    Screen &set(char c) { contents[cursor] = c; return *this; }
    Screen &set(pos r, pos col, char ch) { contents[r * W + col] = ch; return *this; }
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    pos size() { return W * H; }

private:
    void do_display(std::ostream &os) const { os << contents; }
    pos cursor;         //光标

    std::string contents;
};

template <std::string::size_type H, std::string::size_type W> inline
void WindowMgr<H, W>::clear(ScreenIndex screen_index)     // 需要定义为WindowMgr<H, W> //写在后面是因为需要Screen完成定义
{
    if (screen_index < screens.size())              //安全性判断
    {
        Screen<H, W> &s = screens[screen_index];          //增加别名，提高程序可读性
        s.contents = std::string(s.W * s.H, ' ');
    }
}

#endif // _SCREEN_H_