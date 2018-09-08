/**
 * @brief 练习15.39
 * 
 * @file ex15_39.cpp
 * @author huipengly
 * @date 2018-09-08
 */
#include "text_query.h"
#include "Query.h"
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::cerr;
#include <string>
using std::string;

/**
 * @brief 主函数
 * 
 * @param argc 
 * @param argv 第二个参数为读取的文本名
 * @return int 
 */
int main(int argc, char const *argv[])
{
    ifstream is("article.txt");
    TextQuery tq(is);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    print(cout, q.eval(tq)) << endl;
    return 0;
}