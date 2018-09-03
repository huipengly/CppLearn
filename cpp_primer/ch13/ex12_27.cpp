/**
 * @brief 练习12.27
 * 
 * @file ex12_27.cpp
 * @author huipengly
 * @date 2018-08-24
 */
#include "text_query_StrVec.h"
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::cerr;

/**
 * @brief 查询函数
 * 
 * @param infile 需要查询的文本流
 */
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}

/**
 * @brief 主函数
 * 
 * @param argc 
 * @param argv 第二个参数为读取的文本名
 * @return int 
 */
int main(int argc, char const *argv[])
{
    ifstream input;
    if (argc >= 2)
    {
        input.open(argv[1]);
    }
    else
    {
        cerr << "please input filename after program." << endl;
        return -1;
    }
    if (!input)
    {
        cerr << "open file failed!" << endl;
        return -2;
    }
    runQueries(input);
    return 0;
}