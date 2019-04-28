#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int cur = 0, jumpp = 0, next = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			if (cur < i)
			{
				++jumpp;
				cur = next;
			}
			next = std::max(i + nums[i], next);
		}
		return jumpp;
	}
};