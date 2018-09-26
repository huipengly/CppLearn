#include <iostream>
#include <stdexcept>
#include "Query.h"
using namespace std;

// Hints: 为了完成题目，需要将测试用的函数设置为各个类的友元
void cast_test()
{
    AndQuery a1{Query("value1"), Query("value2")};
    QueryBase &b1 = a1;
    try{
        AndQuery a2 = dynamic_cast<AndQuery&>(b1);      // Hints: 这里引用变量转换，<>中要加上&
        if (typeid(a2) == typeid(a1))
            cout << "cast success" << endl;
    } catch (bad_cast &e){
        cout << "cast failed" << endl;
        cout << e.what() << endl;
    }
    
    OrQuery o1{Query("value1"), Query("value2")};
    QueryBase &b2 = o1;
    try{
        AndQuery a3 = dynamic_cast<AndQuery&>(b2);      // Hints: 这里引用变量转换，<>中要加上&
        if (typeid(a3) == typeid(AndQuery))
            cout << "cast success" << endl;
    } catch (bad_cast &e){
        cout << "cast failed" << endl;
        cout << e.what() << endl;
    }
}


int main(int argc, char const *argv[])
{
    cast_test();
    return 0;
}
