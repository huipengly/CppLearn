#ifndef _MY_MAKE_SHARED_
#define _MY_MAKE_SHARED_
#include <memory>

template <typename T, typename... Args> 
std::shared_ptr<T> my_make_shared(Args&&... args)
{
    // return std::shared_ptr<T>(new T(args...));
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));          // Hints:要用forward转发，forward要显式模板参数
}

#endif