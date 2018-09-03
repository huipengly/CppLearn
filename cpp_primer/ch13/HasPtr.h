/**
 * @brief 想添加swap 但是按照书上写的swap不会被调用，被调用的方法参考ex13_31.h，GitHub的写法。fixme:了解原因
 * 
 * @file HasPtr.h
 * @author huipengly
 * @date 2018-09-03
 */
#ifndef _HAS_PTR_H_
#define _HAS_PTR_H_
#include <string>
#include <iostream>

class HasPtr
{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend std::ostream& print(std::ostream &, const HasPtr&);
    // friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
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
    bool operator<(const HasPtr& rhs) const {  return *ps < *rhs.ps; }
    ~HasPtr() { delete ps; }                                                            //!< 析构函数
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    // using std::swap;        // 不加这句第二个交换有问题，为什么第一个没问题？？？
    // swap(lhs.ps, rhs.ps);
    // swap(lhs.i, rhs.i);
    std::cout << "void swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
}

std::ostream& print(std::ostream &os, const HasPtr& rhs)
{
    os << *rhs.ps + " " << rhs.i;
    return os;
}

// bool operator<(const HasPtr &lhs, const HasPtr &rhs)
// {
//     return *lhs.ps < *rhs.ps;
// }

#endif