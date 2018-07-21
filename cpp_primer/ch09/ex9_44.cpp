#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

void replace_string(string &s, const string &old_val, const string &new_val)
{
	for (auto i = 0; i != s.size() - old_val.size(); ++i)
	{
		string s2 = s.substr(i, old_val.size());	// substr返回范围内string的拷贝
		if (s2 == old_val)
		{
			s.replace(i, old_val.size(), new_val);
		}
	}
}

int main()
{
	string s1{ "i tho thru aa!" };
	cout << s1 << endl;
	replace_string(s1, "tho", "though");
	cout << s1 << endl;
	replace_string(s1, "thru", "through");
	cout << s1 << endl;
	return 0;
}