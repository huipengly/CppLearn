#include <iostream>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;

		if (*str == '\0' && *pattern == '\0')
			return true;

		if (*str != '\0' && *pattern == '\0')
			return false;

		if (pattern + 1 != nullptr && *(pattern + 1) != '*')
		{
			if (*str == *pattern || (*pattern == '.' && *str != '\0'))
				return match(++str, ++pattern);
			else
				return false;
		}
		else if (*pattern == '*')
			return match(str, ++pattern);
		else
		{
			if (*str == *pattern || (*pattern == '.' && *str != '\0'))
				return match(str + 1, pattern) || match(str + 1, pattern + 2) || match(str, pattern + 2);
			else
				return match(str, pattern + 2);
		}

	}
};

int main()
{
	Solution s;
	char *str = new char[100]{ "aaa" };
	char *patten = new char[100]{ "a.*a" };
	cout << s.match(str, patten) << endl;
	return 0;
}