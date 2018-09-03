#ifndef _HAS_PTR_H_
#define _HAS_PTR_H_
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}                  //!< 拷贝构造函数
    HasPtr& operator=(const HasPtr &hp)                                                 //!< 拷贝赋值函数
    { 
        auto newp = new std::string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }                                                            //!< 析构函数
private:
    std::string *ps;
    int i;
};

#endif