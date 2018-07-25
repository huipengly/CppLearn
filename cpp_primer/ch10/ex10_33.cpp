/**
 * @brief c++ primer 5th 练习10.33
 * 
 * @file ex10_33.cpp
 * @author huipengly
 * @date 2018-07-25
 */
#include <fstream>
using std::ifstream; using std::ofstream;
#include <iterator>
using std::istream_iterator; using std::ostream_iterator;
#include <iostream>
using std::cerr; using std::endl; using std::cout;

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        cerr << "参数过少！" << endl;
        return -1;
    }

    ifstream ifs(argv[1]);
    ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    if (!ifs && !ofs_odd && !ofs_even)                                      // 判断应该用!ifs
    {
        cerr << "open file error" << endl;
        return -1;
    }

    istream_iterator<int> it_number = ifs, eof;
    ostream_iterator<int> it_odd(ofs_odd, " "), it_even(ofs_even, " ");     // 这里的空格记得使用字符串，不能用字符

    while (it_number != eof)
    {
        if (*it_number & 0x1)
        {
            *it_odd++ = *it_number++;
        }
        else
        {
            *it_even++ = *it_number++;
        }
    }

    return 0;
}
