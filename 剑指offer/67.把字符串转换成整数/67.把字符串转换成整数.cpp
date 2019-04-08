#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;

		bool positive = true;
		int i = 0;
		if (str[0] == '-')
		{
			positive = false;
			++i;
		}
		else if (str[0] == '+')
		{
			++i;
		}

		int value = 0;
		for (; i != str.size(); ++i)
		{
			if (str[i] <= '0' || str[i] >= '9')
				return 0;
			value = value * 10 + str[i] - '0';
		}
		return positive ? value : -value;
	}
};

int main()
{
	Solution s;
	s.StrToInt("1a33");
	return 0;
}