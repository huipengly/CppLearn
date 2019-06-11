#include <vector>
#include <algorithm>
using namespace std;

int maxSum(const vector<int>& nums)
{
	int cur = 0, max = INT_MIN;
	for (int i : nums)
	{
		cur += i;
		max = std::max(max, cur);
		if (cur < 0)
			cur = 0;
	}
	return max;
}