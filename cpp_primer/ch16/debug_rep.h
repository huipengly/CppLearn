#ifndef _DEBUG_REP_H_
#define _DEBUG_REP_H_

#include <string>
#include <sstream>

template <typename T> std::string debug_rep(const T&);
template <typename T> std::string debug_rep(T*);
std::string debug_rep(const std::string&);
std::string debug_rep(const char* str)
{
    return debug_rep(std::string(str));
}

std::string debug_rep(char* str)
{
    return debug_rep(std::string(str));
}

template <typename T> std::string debug_rep(const T& rep)
{
    std::ostringstream ret;
    ret << rep;
    return ret.str();           // 要返回一个string的副本，而不是返回ret
}

template <typename T> std::string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p << " ";
    if (p)
        ret << debug_rep(*p);
    else
        ret << " null pointer.";
    return ret.str();
}

std::string debug_rep(const std::string& str)
{
    return '"' + str + '"';
}

#endif