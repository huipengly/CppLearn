#include <string>
using std::string;

class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		char last_c = 0;
		for (char c : s)
		{
			switch (c)
			{
			case 'M':
				ret += last_c == 'C' ? 800 : 1000;
				break;
			case 'D':
				ret += last_c == 'C' ? 300 : 500;
				break;
			case 'C':
				ret += last_c == 'X' ? 80 : 100;
				break;
			case 'L':
				ret += last_c == 'X' ? 30 : 50;
				break;
			case 'X':
				ret += last_c == 'I' ? 8 : 10;
				break;
			case 'V':
				ret += last_c == 'I' ? 3 : 5;
				break;
			case 'I':
				ret += 1;
				break;
			//default:
			}
			last_c = c;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	string str("LVIII");
	auto ret = s.romanToInt(str);

	return 0;
}