#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    fstream inOut("copyOut.txt", fstream::in | fstream::out | fstream::ate);        // 注意,这里copyOut.txt要存成LF换行的
    if (!inOut)
    {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }
    auto end_mark = inOut.tellg();
    inOut.seekg(0, fstream::beg);
    string s;
    size_t sz = 0;
    while (inOut && inOut.tellg() != end_mark && getline(inOut, s))     // Hints: 先判断位置到没到最后,因为如果先读取的话,最后一行没处理时,流已经到最后了
    {
        sz += s.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, fstream::end);
        inOut << sz;
        if (mark != end_mark)
            inOut << " ";
        inOut.seekg(mark);
    }
    inOut.seekp(0, fstream::end);
    inOut << "\n";
    return 0;
}
