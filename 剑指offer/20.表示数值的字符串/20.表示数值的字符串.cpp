#include <iostream>
using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == nullptr)
			return false;
		bool can_have_dot = true;
		bool can_have_sign = false;
		bool can_have_e = true;
		bool have_number = false;
		int index = 0;

		if (string[index] == '+' || string[index] == '-')
			++index;

		while (string[index] != '\0')
		{
			char c = tolower(string[index]);
			if (c == '+' || c == '-')
			{
				if (can_have_sign)
					can_have_sign = false;
				else
					return false;
			}
			else if (c == 'e')
			{
				if (!can_have_e || !have_number)	// 后面的判断e前是否有数了
					return false;
				else 
				{
					have_number = false;		// e后需要有数字
					can_have_dot = false;
					can_have_sign = true;
					can_have_e = false;
				}
			}
			else if (c == '.')
			{
				if (can_have_dot)
					can_have_dot = false;
				else
					return false;
			}
			else if (c - '0' < 0 || c - '0' > 9)
				return false;
			else if (have_number || c - '0' >= 0 && c - '0' <= 9)	// 解决空串，或者只有符号串
				have_number = true;
			++index;
		}
		return have_number;
	}
};

int main()
{
	Solution s;
	cout << s.isNumeric(new char[100]{ "1+2" }) << endl;
	return 0;
}