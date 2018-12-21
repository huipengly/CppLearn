#include <string>
using std::string; using std::to_string;
#include <algorithm>

class Solution_1 {
public:
	int reverse(int x) {
		int sign = x > 0 ? 1 : -1;
		x = abs(x);
		auto str = to_string(x);
		std::reverse(str.begin(), str.end());
		double rev = std::stod(str);
		if ((rev > INT_MAX) || (rev < INT_MIN))
			return 0;
		return sign * rev;
	}
};

class Solution {
public:
	int reverse(int x) {
		long ret = 0;
		while (x != 0)
		{
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		if ((ret > INT_MAX) || (ret < INT_MIN))
			return 0;
		return ret;
	}
};

int main()
{
	Solution s;
	auto ret = s.reverse(-123);
	return 0;
}
