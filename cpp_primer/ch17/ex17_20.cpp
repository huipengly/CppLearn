#include <string>
#include <iostream>
#include <regex>

using namespace std;

bool valid(const smatch& m)
{
    if (m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    if (!m[1].matched)
        return !m[3].matched && m[4].str() == m[6].str();
}

int main(int argc, char const *argv[])
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    // smatch m;
    string s;
    // while (getline(cin, s))
    s = "(000) 000-0000 (000)-000-0000 000-000-0000 000-000.0000 (111-111-1111";
    {
        cout << s << endl;
        for (sregex_iterator it(s.begin(), s.end(), r), it_end; it != it_end; ++it)
        {
            if (valid(*it))
            {
                cout << "valid: :" << it->str() << endl;
            }
            else
            {
                cout << "not valid: " << it->str() << endl;
            }
        }
    }
    return 0;
}
