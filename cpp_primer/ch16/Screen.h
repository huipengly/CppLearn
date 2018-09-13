#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
#include <iostream>
#include <vector>

template <std::string::size_type, std::string::size_type> class Screen;
template <std::string::size_type H, std::string::size_type W>
    std::istream &operator>>(std::istream &, Screen<H, W> &);           // Hints:这里函数参数是没有const的！！！！！

template <std::string::size_type H, std::string::size_type W>
    std::ostream &operator<<(std::ostream &, const Screen<H, W> &);

template <std::string::size_type H, std::string::size_type W>
class Screen
{
    friend std::ostream &operator<<<H, W>(std::ostream &, const Screen<H, W> &);
    friend std::istream &operator>><H, W>(std::istream &, Screen<H, W> &);

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

template <std::string::size_type H, std::string::size_type W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &screen)
{
    for (auto h = 0; h != H; ++h)
    {
        os << screen.contents.substr(h * W, W) << '\n';
    }
    return os;
}

template <std::string::size_type H, std::string::size_type W>
std::istream &operator>>(std::istream &is, Screen<H, W> &screen)
{
    char c;
    while (screen.cursor != screen.size() && is >> c)
    {
        screen.set(c);
        ++screen.cursor;
    }
    return is;
}

#endif // _SCREEN_H_