#include <iostream>
#include <stdexcept>
#include "Query.h"
using namespace std;

// Hints: 为了完成题目，需要将测试用的函数设置为各个类的友元
void cast_test()
{
    QueryBase *pb1 = new AndQuery(Query("value1"), Query("value2"));
    try{
        if (AndQuery *pa1 = dynamic_cast<AndQuery*>(pb1))
        {
            if (typeid(*pa1) == typeid(AndQuery))
                cout << "cast success." << endl;
            else
                throw bad_alloc();
        }
        else
            throw bad_alloc();
    } catch (const bad_alloc &e){
        cout << e.what() << endl;
    }

    QueryBase *pb2 = new OrQuery(Query("value1"), Query("value2"));
    try{
        if (AndQuery *pa2 = dynamic_cast<AndQuery*>(pb2))
        {
            if (typeid(*pa2) == typeid(AndQuery))
                cout << "cast success." << endl;
            else
                throw bad_alloc();
        }
        else
            throw bad_alloc();
    } catch (const bad_alloc &e){
        cout << e.what() << endl;
    }
}


int main(int argc, char const *argv[])
{
    cast_test();
    return 0;
}
