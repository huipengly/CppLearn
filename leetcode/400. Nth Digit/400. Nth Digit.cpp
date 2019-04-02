#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		if (n < 0)
			return -1;
		if (n < 10)
			return n;

		--n;	// 0-9有10个，考虑了0
		long aux = 9;
		long count = 1;
		while (n > aux * count)
		{
			n -= aux * count;
			++count;
			aux *= 10;
		}

		long number = n / count + pow(10, count - 1);
		auto str = to_string(number);
		return str[n % count] - '0';
	}
};

int main()
{
	Solution s;
	cout << s.findNthDigit(1000000000) << endl;
	return 0;
}