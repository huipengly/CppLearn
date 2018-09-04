#include "String.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<String> vs;
    vs.reserve(100);        // 不加reserve的话，会每次先拷贝时检测空间，不够会扩大
    vs.push_back("aaa");
    vs.push_back("bbb");
    vs.push_back("ccc");
    vs.push_back("ddd");
    // for (auto s : vs)
    // {
    //     cout << s << endl;
    // }
    return 0;
}
