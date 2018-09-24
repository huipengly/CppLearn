#include <regex>
#include <iostream>
#include <string>
using namespace std;

bool valid_zip(const smatch& m)
{
    if (m[1].length() != 5)              // 五位数情况
        return false;
    else if (m[2].matched && !m[3].matched)
        return false;                           // 未匹配到3
    return true;
}

int main(int argc, char const *argv[])
{
    string zip = "(\\d{5})([-])?(\\d{4})?";     // (\\d{5})([-])?(\\d{4})? 这个关系在000000-000也成立.没有表示出仅有五个
    regex r(zip);
    string s;
    // while (getline(cin, s))
    s = "00000 00000-0000 000000000 000000-000";
    {
        for (sregex_iterator it(s.begin(), s.end(), r), it_end; it != it_end; ++it)     // Hints: 这里的iterator要区分不同的类型,例如string的一定要是sregex_iterator
        {
            if (valid_zip(*it))     // *it才是smatch
                cout << "valid zip: " << it->str() << endl;
            else
                cout << "not valid zip: " << it->str() << endl;             // Hints: it要记得转换为字符串
        }
    }
    return 0;
}
