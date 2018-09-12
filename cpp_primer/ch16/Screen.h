#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
using std::string;
#include <iostream>
using std::ostream;
#include <vector>
using std::vector;

template <typename> class Screen;

template <typename T>                                               // Hints:调用模板类，所以这个类也是个模板类
class WindowMgr
{
public:
    using ScreenIndex = typename vector<Screen<T>>::size_type;      // Hints:调用模板类要加<T>
    void clear(ScreenIndex);
private:
    vector<Screen<T>> screens;
};

template <typename T>
class Screen
{
    friend void WindowMgr<T>::clear(WindowMgr<T>::ScreenIndex);     // Hints:模板类的函数，需要在域说明符前的类加<T>

public:
    using pos = T;      // Hints:T前不加typename
    Screen() = default;
    Screen(pos wd, pos ht, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[ r * width + c]; }
    Screen &move(pos r, pos c) { cursor = r * width + c; return *this; }
    Screen &set(char c) { contents[cursor] = c; return *this; }
    Screen &set(pos r, pos col, char ch) { contents[r * width + col] = ch; return *this; }
    Screen &display(ostream &os) { do_display(os); return *this; }
    const Screen &display(ostream &os) const { do_display(os); return *this; }
    pos size() { return width * height; }

private:
    void do_display(ostream &os) const { os << contents; }
    pos height;         //高度
    pos width;          //宽度
    pos cursor;         //光标

    string contents;
};

template <typename T> inline
void WindowMgr<T>::clear(ScreenIndex screen_index)      //卸载后面是因为需要Screen完成定义
{
    if (screen_index < screens.size())                  //安全性判断
    {
        Screen<T> &s = screens[screen_index];           //增加别名，提高程序可读性
                                                        // 调用模板类，需要用Screen<T>
        s.contents = string(s.width * s.height, ' ');
    }
}

#endif // _SCREEN_H_