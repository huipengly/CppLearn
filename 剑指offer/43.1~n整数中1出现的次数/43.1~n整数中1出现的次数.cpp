#include <cmath>
using namespace std;
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		long number = 0;
		for (int i = 0; i != n + 1; ++i)
		{
			number += number_of_1(i);
		}
		return number;
	}
private:
	int number_of_1(int n)
	{
		int ret = 0;
		while (n)
		{
			if (n % 10 == 1)
				++ret;
			n /= 10;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	s.NumberOf1Between1AndN_Solution(1);
	return 0;
}