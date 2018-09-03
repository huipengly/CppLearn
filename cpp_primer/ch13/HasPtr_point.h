/**
 * @brief 练习13.27
 * 
 * @file HasPtr_point.h
 * @author huipengly
 * @date 2018-09-03
 */
#ifndef _HAS_PTR_H_
#define _HAS_PTR_H_
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new int(1)) {}
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i) { ++*use; }
    HasPtr& operator=(const HasPtr &hp);
    ~HasPtr();
private:
    std::string *ps;
    int i;
    int *use;
};

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    use = rhs.use;
    i = rhs.i;
    return *this;
}

#endif